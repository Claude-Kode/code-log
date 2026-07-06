# `__DEBUG_TOOL.h` 知识点讲解（口语版）

> 专门讲 **`source/__DEBUG_TOOL.h`** 里用到的每一个概念。  
> 假设你已经：**会调用 `debug(a,b)`**、**见过** TEMPLATE 里 AI 生成的旧 debug 头（`operator<<` + `dbug`），但 **宏 / 模板底层多半还模糊**。  
> 配套试跑：`source/DEBUG-TOOL-TEST.cpp`

---

## 零、先有一张地图：你敲一行 `debug(vec, mp)` 之后发生了什么

```text
debug(vec, mp)
    │
    ▼  【宏】整行被替换成好几行 C++ 代码
    │
    ├─ 打印 [文件名:行号]
    ├─ 打印 "  vec = " → 调用 print_val(cerr, vec)
    └─ 打印 "  mp = "  → 调用 print_val(cerr, mp)
              │
              ▼  【print_val】看 vec 是什么类型，走对应分支
              │
              ├─ vector → 打 '['，对每个元素再 print_val（递归）
              └─ map     → 打 '{'，对每个 key/value 再 print_val
```

**读源码顺序（由易到难）：**  
`debug 宏` → `print_val` 主函数 → `REGISTER_REFLECT` → `is_map_like` 那些 → `DBG_FOREACH` 宏计数

---

## 一、使用前要懂的「外围知识」

---

### 1. `-DLOCAL` 和 `#ifdef LOCAL`

**为啥会有这玩意？**  
打 CF 时你想本地疯狂 `debug()`，但交 OJ 不能带调试输出，也不能让 debug 代码拖慢或搞乱判题。以前有人维护两份代码（一份带 print、一份不带），很蠢。

**主要干啥？**  
`-DLOCAL` 是告诉编译器：「这次编译定义一个叫 `LOCAL` 的开关」。  
`#ifdef LOCAL` 就是：只有开关打开，才 `#include` debug 头、才编译 debug 相关代码。

**解决了啥？**  
同一份源码：本地 F5 能调试，交题时不定义 `LOCAL` 就不包含头文件——不过你代码里如果还写着 `debug(...)` 且没 stub，交题会编译失败，所以要么删 debug 行，要么以后加「没 LOCAL 时 debug 变空操作」。

**啥场景特别有用？**  
所有「只该在本地存在」的代码：debug、对拍额外输出、慢速检查。

**以后啥问题优先考虑它？**  
你想写 `debug()` / `assert` / 额外日志，第一反应应该是：**包在 `#ifdef LOCAL` 里，并在 tasks.json 加 `-DLOCAL`**。

---

### 2. 头文件 `#include "__DEBUG_TOOL.h"`

**为啥？**  
debug 逻辑几百行，不可能每个题文件复制粘贴。头文件就是「一次写好，到处 `#include`」。

**主要干啥？**  
预处理器把 `__DEBUG_TOOL.h` 的内容 **原样插入** 到你 `#include` 那一行。

**解决了啥？**  
改 debug 工具只改一个文件；所有题共用。

**啥场景？**  
任何想复用的模板、debug、数据结构定义。

**优先考虑？**  
超过 ~30 行、且多题复用的代码 → 抽到头文件。

---

### 3. 头文件守卫 `#ifndef DEBUG_HPP` / `#define` / `#endif`

**为啥？**  
万一两个头文件都 `#include` 了 debug，或者你不小心 include 两次，同一个函数/宏会被定义两遍，编译器报错「重复定义」。

**主要干啥？**  
第一次 include：定义 `DEBUG_HPP`，展开内容。  
第二次 include：发现 `DEBUG_HPP` 已定义，**整文件跳过**。

**解决了啥？**  
重复 include 的安全问题。

**啥场景？**  
所有 `.h` 头文件都应该有（或用 `#pragma once`）。

**优先考虑？**  
你自己写 `.h` 时，顶部固定三件套。

---

### 4. `namespace debug_detail` 和 `namespace refl`

**为啥？**  
头文件里函数名、结构体名很多，和你在 `solve()` 里起的变量名、函数名容易撞车。

**主要干啥？**  
把「内部实现」关进命名空间，相当于加前缀 `debug_detail::print_val`。

**解决了啥？**  
名字污染；你一看 `debug_detail` 就知道是库内部东西。

**啥场景？**  
库代码、工具头文件。

**优先考虑？**  
写给别人 include 的工具时，实现细节放 namespace，对外只暴露 `debug()` 宏。

---

## 二、输出相关：为啥用 `cerr`，不用 `cout`

---

### 5. `std::cout`（标准输出）

**为啥有？**  
程序总要有个默认「往终端写答案」的口子。

**主要干啥？**  
你 `cout << ans` 的内容，判题机就是读这个。

**解决了啥？**  
程序和外界通信。

**啥场景？**  
**所有正式答案**。

**优先考虑？**  
交题输出 **只用 cout**（或 printf），别把 debug 打这里。

---

### 6. `std::cerr`（标准错误）

**为啥有？**  
作者意识到：除了答案，你还想打日志、警告，且 **不想和答案混在一起**。

**主要干啥？**  
`debug()` 全部输出到 `cerr`。本地终端里你能看到，判题一般 **不拿 cerr 判对错**。

**解决了啥？**  
debug 污染 stdout 导致 WA（有些本地对拍也会搞混）。

**啥场景？**  
调试信息、警告、进度条。

**优先考虑？**  
任何 **不是答案** 的打印 → cerr 或 LOCAL 宏控制的 debug。

---

### 7. `operator<<` 和链式 `os << a << b`

**为啥有？**  
让输出写起来像自然拼接：`cout << x << y`，而不是一连串函数名。

**主要干啥？**  
`os << val` 就是「把 val 按某种格式写进流 os」。

**解决了啥？**  
统一的输出接口；自定义类型也能输出（如果你写了 `operator<<`）。

**在本头文件里？**  
`print_val` 内部大量 `os << '{'`、`os << name`；最后一层 `os << val` 是碰运气：看类型有没有现成的 `<<`。

**啥场景？**  
所有 iostream 输出；旧 debug 头给 vector/map 写 `operator<<` 就是这个思路。

**优先考虑？**  
- 简单 struct、只在一题里 debug → 手写 `operator<<` 就够  
- 要自动支持嵌套、多类型 → 用本文件的 `print_val` 递归

---

### 8. `__FILE__` 和 `__LINE__`

**为啥有？**  
debug 时你最想知道：**这行 print 是哪个文件的第几行**，不然一堆输出对不上代码。

**主要干啥？**  
编译器自动填的字符串和整数，不用你手写。

**解决了啥？**  
「输出是从哪来的」定位问题。

**啥场景？**  
任何 debug 宏、日志宏。

**优先考虑？**  
自己写 debug 宏时一定带上这俩。

---

## 三、宏：`debug()` 为什么能一次打多个变量

> 这块是整文件 **最难读** 的部分。你可以 **先会用，后理解**。

---

### 9. `#define` 宏（文本替换）

**为啥有？**  
C 时代没有 inline 函数、constexpr，想在编译期做「开关、短写法」，就直接在源码里做文本替换。

**主要干啥？**  
`#define debug(...) ...` 表示：源码里每次出现 `debug(...)`，预处理阶段替换成 `#define` 右边那坨。

**解决了啥？**  
`debug(a,b,c)` 不用手写三份打印；`LOCAL` 开关。

**啥场景？**  
CP 短小的 debug 宏、O2 优化 pragma。

**优先考虑？**  
- 几行、纯复制粘贴式展开 → 宏可以  
- 复杂逻辑、要类型检查 → 优先模板/inline 函数

---

### 10. `#var`（字符串化）

**为啥有？**  
你想打印 `vec` 的值，也想打印 **变量名叫 "vec"**，手写太烦。

**主要干啥？**  
`#vec` → 编译前变成字符串 `"vec"`。

**在本文件？**  
`DBG_PRINT_ONE` 里 `#var`，所以输出是 `  vec = [1,2,3]` 而不是 `[1,2,3]`。

**解决了啥？**  
debug 可读性。

**啥场景？**  
`dbug(x)`、`debug(x)` 一类宏。

**优先考虑？**  
写 debug 宏几乎必用 `#x`。

---

### 11. `DBG_PRINT_ONE(var)` 宏

**为啥有？**  
把「打印一个变量」抽成最小单元，方便被 `DBG_FOREACH` 重复调用。

**主要干啥？**  
展开成三行：`cerr << "  " << #var << " = ";` → `print_val(...)` → `cerr << '\n';`

**注意：** 这里 **故意不用** `do { } while(0)`，因为多个 `DBG_PRINT_ONE` 会 **首尾相接** 排成多行；如果用 do-while 且中间没分号，宏链会报 `expected ';' before 'do'`（你之前踩过的坑）。

**解决了啥？**  
一个变量一行格式统一的输出。

---

### 12. `DBG_N(...)` —— 数你有几个参数

**为啥有？**  
`debug(a,b,c)` 有三个变量，宏需要知道是 3，才能展开成 3 次 `DBG_PRINT_ONE`。

**主要干啥？**  
经典 CPP 技巧：  
`DBG_N(a,b,c)` → 往参数后面塞 `15,14,...,1,0`，数第几个是 `N` → 得到 3。

**解决了啥？**  
C 宏没有「参数个数」内置函数，只能这样数。

**啥场景？**  
`debug(...)`、`REGISTER_REFLECT` 数成员个数。

**优先考虑？**  
几乎只有写 **通用 debug 库** 才需要自己写；使用者知道「最多 15 个变量」即可。

---

### 13. `DBG_CAT(a, b)` —— 宏拼接

**为啥有？**  
知道个数是 3 以后，要拼出宏名 `DBG_MAP_3`，不能写死。

**主要干啥？**  
`DBG_CAT(DBG_MAP_, 3)` → `DBG_MAP_3`。  
**关键细节：** 必须 `DBG_CAT_I` 间接一层，否则 `DBG_CAT(DBG_MAP_, DBG_N(...))` 不会先展开 `DBG_N`（你又踩过的坑）。

**解决了啥？**  
根据参数个数 **动态选** 不同宏。

---

### 14. `DBG_MAP_1` … `DBG_MAP_15` 和 `DBG_FOREACH`

**为啥有？**  
参数个数不同，要展开的 `DBG_PRINT_ONE` 次数不同。

**主要干啥？**  
- `DBG_MAP_1(m, x)` → `m(x)`  
- `DBG_MAP_3(m, x, y, z)` → `m(x) m(y) m(z)`  

`DBG_FOREACH(DBG_PRINT_ONE, a, b, c)` 最终变成三次 `DBG_PRINT_ONE`。

**解决了啥？**  
`debug(a,b,c)` 一行源码 → 多行打印。

---

### 15. `debug(...)` 宏和 `do { } while(0)`

**为啥有？**  
宏展开后可能是多条语句；如果写 `if (x) debug(a);` 而宏不用 do-while 包起来，容易出 **悬挂 else** 等经典宏 bug。

**主要干啥？**  
整个 `debug(...)` 包在 `do { ... } while(0)` 里，语法上算 **一条语句**。

**解决了啥？**  
宏在 if/for 后面安全使用。

**啥场景？**  
任何多语句宏。

**优先考虑？**  
自己写 `MY_MACRO(...)` 且里面超过一行 → 外层 do-while。

---

## 四、核心：`print_val` —— 整个头文件的心脏

---

### 16. 函数模板 `template<typename T> print_val(...)`

**为啥有？**  
你要打印 `int`、`vector<int>`、`map<string, Node>`…… 不可能写几十个同名函数。

**主要干啥？**  
一份模板代码，编译器 **看你传什么类型，自动生成对应版本**。

**解决了啥？**  
旧 debug 头要给 vector、set、map、pair 各写一份 `operator<<`；这里 **一个 print_val + 分支** 搞定。

**啥场景？**  
类型很多种、逻辑类似的工具函数。

**优先考虑？**  
「同一套逻辑，类型不同」→ 模板；「就两种类型」→ 两个重载也行。

---

### 17. 前向声明 `print_val`（163–164 行）

**为啥有？**  
`print_tuple` 里要调 `print_val`，但 `print_val` 定义在后面；模板又互相递归调用。

**主要干啥？**  
先告诉编译器「有个叫 print_val 的模板存在」，后面再写完整定义。

**解决了啥？**  
编译顺序问题。

**啥场景？**  
互相调用的模板函数。

---

### 18. `const T& val`（常量引用传参）

**为啥有？**  
`vector` 很大，传值会 **拷贝整份 vector**，debug 一下慢死。

**主要干啥？**  
`const T&` = 只读引用，不拷贝，也不能改原变量。

**解决了啥？**  
大容器 debug 的性能和正确性。

**啥场景？**  
只读、可能很大的参数 → 几乎总是 `const T&`。

**优先考虑？**  
函数参数是 vector/map/string → 默认 `const auto&` 或 `const T&`。

---

### 19. `std::decay_t<T>`（去掉引用等「外壳」）

**为啥有？**  
传进来可能是 `int&`、`const vector<int>&`，但你想问的是「**本质类型**是不是 map」。

**主要干啥？**  
`decay_t` 把引用、const 等剥掉，得到「干净类型」`D`，后面 `is_same_v<D, bool>` 才可靠。

**解决了啥？**  
类型判断不因「传的是引用」而失败。

**啥场景？**  
模板里做类型分支。

**优先考虑？**  
`if constexpr (is_same_v<decay_t<T>, ...>)` 这种写法。

---

### 20. `if constexpr`（编译期 if）

**为啥有？**  
普通 `if` 在模板里：**两个分支都必须能编译**。  
比如 `if (是map) 用[k,v]` else `用 begin/end`，假分支编译不过就整个报错。

**主要干啥？**  
**不满足的分支直接扔掉**，不参与编译。

**解决了啥？**  
一个 `print_val` 里写十几种类型分支。

**啥场景？**  
模板里按类型走完全不同的代码。

**优先考虑？**  
模板泛型工具；普通 `solve()` 里写 `if constexpr` 很少需要。

---

### 21. 递归：`print_val` 调 `print_val`

**为啥有？**  
`vector<vector<int>>`：外层是 vector，元素还是 vector，再里面才是 int。一层逻辑搞不定。

**主要干啥？**  
打 vector 时对每个元素 `print_val(os, e)`；  
打 map 时对 key、value 各 `print_val` 一次。

**解决了啥？**  
**任意嵌套**（map 里 vector 里 pair 里 Node…）。

**啥场景？**  
树、嵌套容器、JSON 式结构打印。

**优先考虑？**  
「结构里面还有同类型或子结构」→ 想递归，别写死层数。

**调用顺序图（重要）：**

```text
print_val(map<int, vector<Node>>)
  → map 分支
      → print_val(int key)
      → print_val(vector<Node>)
            → vector 分支
                → print_val(Node)
                      → refl 分支（若 REGISTER_REFLECT）
                            → print_val(每个成员)
```

---

## 五、`print_val` 里每一类分支（按判断顺序）

> **顺序不能乱**：比如 string 也有 begin/end，必须先当 string 处理，不能先进「可迭代」分支打成字符数组。

---

### 22. 基础类型分支（bool / char / 数字 / string / 指针）

**为啥单独写？**  
- `bool` 默认可能打 `0/1`，你想看 `true/false`  
- `char` 打出来是 ASCII 码，你想看 `'a'`  
- `string` 若走「可迭代」会变成 `['h','e','l','l','o']`  
- 指针直接 `<<` 可能不好看，打地址更清晰  

**主要干啥？**  
人类可读的 debug 格式。

**解决了啥?**  
「输出看起来对但很难读」的问题。

**优先考虑？**  
写 debug 工具时，**特殊类型先 special case**，通用规则放后面。

---

### 23. `is_pair` + pair 分支

**为啥？**  
`pair` 太常用，且只有 `.first/.second`，格式固定成 `(a, b)` 最好认。

**主要干啥？**  
特判 `pair<A,B>`，不走后面的 generic 逻辑。

**解决了啥？**  
C++23 里 pair 也有 begin/end 了，若不特判可能被当「可迭代」打错。

**啥场景？**  
Dijkstra 的 `{v, dis}`、map 里存 pair 等。

**优先考虑？**  
看到 `pair` → 期望 `(x, y)` 格式。

---

### 24. `is_tuple_like` + tuple / `index_sequence`

**为啥？**  
`tuple` 元素个数编译期才知道，不能手写 `.first/.second/.third` 到死。

**主要干啥？**  
- `tuple_size` 知道有几个元素  
- `index_sequence<0,1,2,...>` 生成序号  
- `print_tuple_elem<0>`, `<1>`… 每个调一次 `print_val`  

**解决了啥？**  
可变元素个数的聚合类型打印。

**啥场景？**  
`tuple<int,string,double>` 等（CP 相对少，但头文件要完整）。

**优先考虑？**  
元素个数固定但 >2 → 有时 `tuple`；多数 CP 用 `pair` 或 struct 就够。

---

### 25. `is_map_like`（有 `mapped_type` 就当 map）

**为啥？**  
`map`、`unordered_map`、`multimap` 接口类似，不想每种写一遍。

**主要干啥？**  
编译期问：「这个类型有没有 `mapped_type`？」有就当键值表。

**格式：** `{k1: v1, k2: v2}`

**解决了啥？**  
map 族统一处理。

**啥场景？**  
离散化、计数、邻接表存权值等。

**注意：** 必须在 `is_iterable` **之前**判断，因为 map 也能 for 循环。

---

### 26. `is_set_like`（有 `key_type` 且不像 map）

**为啥？**  
`set`、`multiset`、`unordered_set` 只有「值」没有 mapped_value。

**主要干啥？**  
格式：`{1, 2, 3}`

**解决了啥？**  
集合族统一打印。

**啥场景？**  
去重、动态有序集合、multiset 计数。

**注意：** `unordered_map` 也有 `key_type`，所以必须 **先排除 map_like**。

---

### 27. `is_iterable`（有 begin/end 就当序列）

**为啥？**  
`vector`、`array`、`deque`、`list`…… 都能 for 循环，格式统一 `[a, b, c]`。

**主要干啥？**  
catch-all 序列容器。

**解决了啥？**  
不用给每种容器写 overload。

**啥场景？**  
默认序列几乎都用 vector；二维就是 `vector<vector<int>>`。

**优先考虑？**  
-debug 时 90% 是 vector / vector<vector<>>。

---

### 28. 最后一层 `os << val`（fallback）

**为啥？**  
总有些类型上面都没覆盖到，但 **你自己写过 `operator<<`**（比如 `mint`）。

**主要干啥？**  
碰运气走你自定义的流输出。

**解决了啥？**  
扩展点：不想 REGISTER_REFLECT，就写 `operator<<`。

**啥场景？**  
模数类、复杂格式、第三方类型。

**优先考虑？**  
- struct 要成员名 → `REGISTER_REFLECT`  
- 只关心值、已有 `<<` → fallback 够用

---

## 六、结构体：`REGISTER_REFLECT` 整套

---

### 29. 为什么 C++ 不能自动打印「成员名: 值」

**痛点：**  
Python 的 dataclass、dict 能知道字段名；C++ 编译完 **成员名基本消失**，运行时只剩内存布局，没有「叫 x 的 int」这种元数据（C++26 反射以后才会好办）。

**所以：**  
必须 **你告诉工具**：Node 有 x、y 两个成员。这就是 REGISTER_REFLECT 存在的原因。

---

### 30. `#m1` 在 `_REFL_BODY_1` 里

**主要干啥？**  
`f(#m1, (obj).m1)` → 调用回调 `f`，第一个参数是字符串 `"x"`，第二个是 `obj.x` 的值。

**解决了啥？**  
成员名 + 成员值同时交给打印逻辑。

---

### 31. `refl_traits<Type>` 模板特化

**为啥？**  
默认 `refl_traits<T>::available = false`（普通类型没注册）；  
你写 `REGISTER_REFLECT(Node, x, y)` 后，**专门给 Node 写一份特化**，`available = true`，并带上 `for_each`。

**主要干啥？**  
编译期查表：「Node 有没有注册反射？」有就走 struct 分支。

**解决了啥？**  
不用改 `print_val` 源码就能支持新 struct。

**啥场景？**  
每个自定义 struct 注册一次。

**优先考虑？**  
- 题内 debug struct → `REGISTER_REFLECT` 一行  
- 成员 >10 个 → 考虑手写 `operator<<` 或拆 struct

---

### 32. lambda：`for_each(val, [&](const char* name, const auto& member) { ... })`

**为啥？**  
`for_each` 不知道你要「打印」还是「序列化」，所以传一个 **回调** 给你，你对每个成员执行啥逻辑。

**主要干啥？**  
在 `print_val` 的 struct 分支里：  
对每个成员 `os << name << ": "; print_val(os, member);`

**解决了啥？**  
反射遍历 和 具体打印格式 解耦。

**啥场景？**  
STL 算法、`for_each` 容器、主席树 lambda 递归——同一套路。

**优先考虑？**  
「对每个元素做同一件事」→ lambda + 循环/for_each。

---

### 33. 结构化绑定 `for (const auto& [k, v] : val)`（map 分支）

**为啥？**  
map 每个元素是 pair，拆成 key/value 写起来烦。

**主要干啥？**  
循环里直接 `[k, v]` 两个名字。

**解决了啥？**  
少写 `.first/.second`。

**啥场景？**  
遍历 map、pair 数组（CP 极常见）。

---

## 七、进阶类型探测（读不懂可先跳过）

---

### 34. SFINAE + `std::void_t<...>`

**口语解释：**  
编译器在 **匹配模板** 时，如果某种写法 **不合法**，不是立刻报错，而是 **假装这个模板不存在**，换别的候选——这叫 SFINAE。

**在本文件：**  
「如果 `T` 有 `mapped_type`，就用 `is_map_like` 特化版本，否则用默认 false」。

**解决了啥？**  
不用 C++20 concept 也能做「类型有没有某成员」的判断。

**啥时候你需要写？**  
几乎只有写 **通用库** 时；会用 `debug()` 不用会写。

---

### 35. `std::false_type` / `std::true_type` / `::value`

**主要干啥？**  
编译期布尔值包装：`is_map_like<T>::value` 在 `if constexpr` 里当 true/false。

**解决了啥？**  
模板元编程的统一写法。

---

### 36. fold expression `(print_tuple_elem<Is>(os, tup), ...)`

**主要干啥？**  
把参数包 `Is...` 展开成多句表达式，用逗号运算符串起来。

**解决了啥？**  
C++17 之前打印 tuple 更丑；现在一行展开。

**啥场景？**  
tuple、可变模板参数展开。

---

## 八、和 TEMPLATE 里「旧 AI debug 头」的对比（帮你衔接已有认知）

| | 旧头（你略读过） | 新 `__DEBUG_TOOL.h` |
|--|------------------|---------------------|
| **思路** | 给每种容器写一个 `operator<<` | 一个 `print_val` + 类型分支 + 递归 |
| **多变量** | `dbug(x)` 一次一个 | `debug(a,b,c)` 最多 15 个 |
| **结构体** | `DBG_STRUCT` + `DBG_MEMBER` 宏写 `<<` | `REGISTER_REFLECT` |
| **输出流** |  mostly `cout` | `cerr`（更安全） |
| **unordered_map / multiset** | 旧版未必全有 | 有 |
| **学习难度** | 较低，像「抄 operator<<」 | 较高，但功能全 |
| **建议** | 用来 **理解 operator<< 和 #x** | 日常 **主力用**；读源码按本文顺序 |

**你之前「简单看过」旧头 ≈ 知道了：** 容器可以重载 `<<`、`#x` 能出变量名、`LOCAL` 开关。  
**新头多出来的核心就三样：** `print_val` 递归、`if constexpr` 分类型、`REGISTER_REFLECT` 注册成员。

---

## 九、常见问题（踩坑对照表）

| 现象 | 原因 | 怎么办 |
|------|------|--------|
| `debug was not declared` | 没 `-DLOCAL` 或没 include | tasks.json 加 `-DLOCAL` + `#ifdef LOCAL` include |
| 宏展开报错 `DEBUG_MAP_IMPL_xxx` | 宏拼接没间接展开 | 已用 `DBG_CAT_I` 修复 |
| struct 编译报错 `no match for operator<<` | 没 REGISTER_REFLECT 也没写 `<<` | 加 `REGISTER_REFLECT` 或手写 `operator<<` |
| string 打成 `['a','b']` | string 被当 iterable | 本头已先判 string；自己写时记得顺序 |
| 交 OJ RE/PE | debug 打到 cout | 用 cerr + LOCAL |
| `debug()` 超 15 个变量 | 宏计数上限 | 拆两次 debug，或改大 DBG_MAP |

---

## 十、学习路径（只学本 hpp）

| 阶段 | 读什么 | 目标 |
|------|--------|------|
| **1** | 本文「零、地图」+ 用法注释 | 会调，不 panic |
| **2** | `print_val` 218–302 行 | 能解释 vector/map 怎么打出来 |
| **3** | `REGISTER_REFLECT` + struct 分支 | 会给 Node 注册 |
| **4** | `DBG_PRINT_ONE` + `debug` 宏 | 知道 `#var`、`__LINE__` |
| **5** | `is_map_like` 等 | 理解「编译期问类型」 |
| **6** | `DBG_N` / `DBG_FOREACH` | 能改「最多几个变量」 |

**自测三题：**

1. `debug(g)`，`g` 是 `vector<vector<int>>`，输出怎么递归出来的？  
2. 为什么 map 的判断要在 vector 风格循环 **之前**？  
3. `REGISTER_REFLECT(Edge, u, v, w)` 之后，`print_val` 怎么知道打印 `u:` 而不是数字 0/1/2？

---

## 十一、和其他文档的关系

| 文档 | 内容 |
|------|------|
| **本文** | 只讲 `__DEBUG_TOOL.h` 里每个知识点 |
| `notes/CPP-LEVEL-AND-ROADMAP.md` | 你的整体 C++ 水平 + 更广的 CP/工程路线 |
| `templates/TEMPLATE-FUNCTIONS.md` | 板子清单 + 旧 debug 头源码 |
| `source/__DEBUG_TOOL.h` 顶部注释 | 快速用法 + 读源码顺序 |

---

*写给你当前水平：会 CP 板子、旧 debug 头略读、新头 mainly 会用。讲解刻意口语化，避免默认你已懂 SFINAE。*
