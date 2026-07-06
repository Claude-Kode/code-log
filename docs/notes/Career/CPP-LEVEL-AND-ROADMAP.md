# C++ 水平画像 · 评估 · 知识点百科 · 学习路线

> 基准：`templates/TEMPLATE-FUNCTIONS.md` 里出现的全部内容 = **你目前会用的上限**。  
> 本文 **不高估** 你的水平；工程开发、系统原理、模板元编程 **默认未掌握**，除非你在别处单独学过。

---

## 一、对你目前 C++ 水平的最准确描述（可直接当「自我介绍」用）

你现在的 C++ 能力，可以概括为：

**「竞赛编程（Competitive Programming）导向的 C++ 单文件脚本型选手」**。

具体来说：

1. **程序形态**：习惯写一个（或少数几个）`.cpp` 文件，从 `main` 读入、在 `solve()` 里写逻辑、向标准输出打印答案；**没有**多文件工程、库封装、构建系统（CMake）、长期维护项目的经验。

2. **知识来源**：主要依赖 `bits/stdc++.h` 万能头、自己的 `TEMPLATE-FUNCTIONS.md` 模板库、以及从题解/板子 **复制—改参数—能跑**；对很多语法是 **「会用但说不清编译器在背后做了什么」**。

3. **算法与数据结构**：能按模板使用并查集、树状数组、线段树（含 lazy 模板类）、图论最短路/LCA、分块、主席树、珂朵莉树、pb_ds 等；**算法思路** often 强于 **语言底层**。

4. **C++ 语法使用面**（会用的）：
   - `vector / map / set / pair / array / tuple` 等 STL 容器；
   - 范围 for、`auto`、结构化绑定 `auto [u, w] = ...`；
   - 简单 `class` / `struct`、运算符重载（如 `mint`）；
   - 函数模板 **照抄**（如 `operator<<` 打印容器、`template<typename T>` 的 debug）；
   - `lambda` 当回调用（Dijkstra 的 `cmp`、主席树的 `auto&& sef`）；
   - 宏的 **开关用法**（`#ifdef LOCAL`、`#define dbug(x)`），不是宏 **编写者**；
   - 位运算、`__builtin_*`、 `#pragma GCC optimize`；
   - `freopen` 文件 IO、本地 `g++` 一条命令编译、对拍脚本 `system()`。

5. **明确偏弱或未系统学过的**：
   - C++ **编译链接全流程**（预处理 / 编译 / 链接各自干什么）；
   - **为什么** 头文件要 `#ifndef`、为什么 `LOCAL` 没定义会报错；
   - `iostream` 机制（`cout` vs `cerr`、缓冲区、`operator<<` 链式调用）；
   - 模板 **原理**（实例化、特化、SFINAE、`if constexpr`）；
   - 宏 **展开规则**（`##` 拼接、可变参数计数）—— 所以读 `__DEBUG_TOOL.h` 会觉得「一整片陌生」；
   - 内存模型（栈/堆、指针生命周期、智能指针、RAII）；
   - 异常、多线程、网络、数据库等 **工程向** 内容；
   - 读标准库 / 第三方库 **源码** 并修改的能力。

6. **学习状态**：正在从「只会抄板子过题」向「理解工具怎么工作、能写小工具（如 debug 头文件）」过渡；同时也在学 Python，但 C++ 仍是 CP 主语言。

**一句话**：你能 **用 C++ 解决算法题并调试**，但还 **不是** 能独立设计、拆分、测试、发布一个 C++ 工程程序的开发者——这很正常，也和你的学习路径一致。

---

## 二、水准评估（保守、不夸大）

### 2.1 分级对照（10 分制，CP 与工程分开）

| 维度 | 分数 | 说明 |
|------|------|------|
| **CP 单题实现** | 7/10 | 模板齐全，图论/DS 覆盖面广 |
| **CP 模板理解与改造** | 4–5/10 | 线段树 `Info/Tag` 曾留空；改 lazy 规则常需对照题解 |
| **STL 日常使用** | 6/10 | 容器、算法库函数会用；corner case（如 `vector<bool>`）可能踩坑 |
| **C++ 语法系统理解** | 3/10 | 会写 `template`，难解释「何时实例化、为何报错」 |
| **预处理 / 宏** | 2/10 | 会用 `LOCAL`/`dbug`；难独立写 `DBG_FOREACH` 级宏 |
| **编译与构建** | 2/10 | 会 `g++ file.cpp -o a`；不熟多文件、静态库、CMake |
| **调试与测试** | 4/10 | 对拍、freopen 熟练；单元测试框架未用 |
| **工程 / 软件设计** | 1/10 | 自述无工程经验；无模块边界、接口设计实践 |
| **阅读他人复杂头文件** | 2–3/10 | `__DEBUG_TOOL.h` 需分段学，不能一次通读 |

**综合（若目标是 CP）**：约 **CF/AtCoder 黄～橙段常见 C++ 工具型水平**——题能写，语言当「带 STL 的脚本」。

**综合（若目标是软件工程）**：约 **入门前期**——需从零补编译原理、内存、项目结构。

### 2.2 优势（应保留）

- 递归、分治、复杂度直觉好；
- 不怕长代码，敢用类封装数据结构；
- 已有 **本地调试意识**（LOCAL、对拍、文件 IO）；
- 文档化习惯好（`TEMPLATE-FUNCTIONS.md` 本身就是资产）。

### 2.3 短板（学 `__DEBUG_TOOL.h` 和工程的前置缺口）

| 缺口 | 表现 |
|------|------|
| 编译期 vs 运行期 | 分不清宏、`constexpr`、`if constexpr` 何时生效 |
| 类型系统 | 看到 `is_map_like<T>::value` 不知道在「问类型问题」 |
| IO 抽象 | `operator<<` 只知抄，不知「为自定义类型提供打印协议」 |
| 反射 | 知 C++ 没有自动成员名，但不熟「注册宏」设计模式 |
| 项目结构 | 单文件 `#include "xxx.h"` 易路径/宏配置出错（你已遇到过） |

---

## 三、对照 `TEMPLATE-FUNCTIONS.md`：你已「会」的内容清单

> 以下 = 文档里出现过的能力。  
> 「会」= **能照着写或改参数使用**，不等于 **能从头推导或讲清原理**。

### 3.1 工具链

| 条目 | 你会什么 |
|------|----------|
| freopen | 重定向 stdin/stdout/stderr 到文件 |
| g++ 命令 | `-std=c++14/23 -O2 -Wall` 等常用 flags |
| LOCAL + debug 头 | `#ifdef LOCAL` 包含 debug；`dbug(x)` / `operator<<` 打容器 |
| GCC 优化 pragma | `-Ofast`、`-funroll-loops`、`-mavx2` 等加速 |
| 对拍 | generator + brute + fc 比较 + TLE 检测 |

### 3.2 语言 / STL 片段

| 条目 | 你会什么 |
|------|----------|
| 位运算技巧 | lowbit、popcount、ctz、clz 等 |
| 随机 | `mt19937`、`uniform_int_distribution` |
| 数学 | 快速幂、逆元、筛、组合数预处理、mint 类 |
| 离散化 | dedup / getId / ranked |
| 图 | Prim、Dijkstra、Floyd、SPFA、LCA、链式前向星 |
| DS | DSU、回滚 DSU、带权 DSU、BIT、线段树、主席树、分块、ODT、ST、Trie、pb_ds |
| 语法糖 | lambda、结构化绑定、折叠表达式（tuple 输出里 **用过**） |

---

## 四、你还没有、但建议补上的知识（按优先级）

### P0 — 读 debug 头文件 / 少踩编译坑（1～2 周）

编译流程、头文件、iostream、引用、模板函数入门、宏基础。

### P1 — 能把板子改成自己的（2～4 周）

类与 struct 区别、const、static、explicit、运算符重载语义、简单模板特化。

### P2 — 小工程能力（1～2 月）

多 `.cpp` + `.h` 拆分、`CMakeLists.txt` 或固定 tasks.json、命名空间、`-DLOCAL` 统一管理。

### P3 — 进阶 C++（按需）

智能指针、移动语义、异常、多线程、`concept`（C++20）。

### P4 — 与 Python 项目联动（你已在走）

`cf_service.py` 类小服务：API、异步、模块导入——和 CP 的 C++ **互补**，不必强行全用 C++ 写。

---

## 五、知识点百科

> 格式：**是什么 → 为什么发明 → 解决什么问题 → 主要用途 → 建议何时使用**  
> 文中 `//` 行是「可当成代码注释读」的短句。

---

### 模块 A：从源码到程序（必补基础）

#### A1. 预处理（Preprocessor）

```cpp
// 在真正的编译之前，另一段程序先把你的源码「按文本规则」改写完
#define LOCAL          // 定义宏名字（无值）
#ifdef LOCAL           // 若定义过 LOCAL，保留下面代码；否则整段删掉
#include "__DEBUG_TOOL.h"
#endif
```

| 项 | 内容 |
|----|------|
| **为什么** | 早期 C 需要「编译期开关、常量替换」；比复制粘贴维护一份 Debug 版源码省事 |
| **解决什么** | 同一套代码：本地带调试、交 OJ 不带调试 |
| **用途** | `LOCAL`、`dbug`、`#pragma GCC optimize`、条件包含头文件 |
| **何时用** | CP 本地调试；**不要**在不了解展开结果时写复杂宏（易 bug） |

#### A2. 编译与链接

```text
// .cpp --[预处理]--> .i --[编译]--> .o --[链接]--> .exe
// 多个 .cpp 各自编译成 .o，链接器把 main 和所有函数符号拼成最终程序
```

| 项 | 内容 |
|----|------|
| **为什么** | 大项目拆分文件、复用已编译目标文件，加快构建 |
| **解决什么** | 「声明在 .h、实现在 .cpp」如何变成 ONE 可执行文件 |
| **用途** | 理解「为什么只改头文件有时要全量重编」「undefined reference 是什么」 |
| **何时用** | 开始多文件项目、链接静态库、报错 `undefined reference to` 时 |

#### A3. 头文件与 `#include`

```cpp
#ifndef DEBUG_HPP   // 若未定义过 DEBUG_HPP
#define DEBUG_HPP   // 则定义它，并包含下面内容
// ... 整份头文件 ...
#endif              // 第二次 #include 时上面跳过，避免重复定义
```

| 项 | 内容 |
|----|------|
| **为什么** | 声明共享；避免每个 `.cpp` 复制一遍类定义 |
| **解决什么** | 重复定义、循环依赖 |
| **用途** | `__DEBUG_TOOL.h`、`bits/stdc++.h`（CP 偷懒用） |
| **何时用** | 任何跨文件复用的代码；工程里 **少依赖** `bits/stdc++.h` |

---

### 模块 B：输入输出（你已用，建议加深）

#### B1. `cin` / `cout` / `cerr`

```cpp
cin >> n;                    // 从标准输入读（交题答案来源）
cout << ans << '\n';         // 写到标准输出（判题看这里）
cerr << "debug: " << n;      // 写到标准错误（判题一般忽略）
```

| 项 | 内容 |
|----|------|
| **为什么** | 统一抽象「流」；程序和终端/文件解耦 |
| **解决什么** | 不用手写 `read/write 系统调用` |
| **用途** | 答题输出；调试信息应走 **cerr** 或 LOCAL 宏，避免污染 stdout |
| **何时用** | 所有 IO；对拍时注意 stdout 只能有答案 |

#### B2. `ios::sync_with_stdio(false)` + `tie(nullptr)`

```cpp
// 关闭 C++ 流与 C stdio 的同步，解除 cin/cout 绑定，大量 IO 时更快
ios::sync_with_stdio(false);
cin.tie(nullptr);
```

| 项 | 内容 |
|----|------|
| **为什么** | 兼容 C 的 `printf` 与 `cout` 混用时需要同步；CP 只用一个时可关 |
| **解决什么** | 大数据 IO TLE |
| **何时用** | 1e5 级以上读写；**混用 printf/scanf 与 iostream 时要谨慎** |

#### B3. `operator<<` 重载

```cpp
// 让 cout << myObj 知道怎么打印 myObj
ostream& operator<<(ostream& os, const Node& s) {
  return os << s.x << ' ' << s.y;
}
```

| 项 | 内容 |
|----|------|
| **为什么** | 用户定义类型默认不能 `<<` |
| **解决什么** | 统一打印接口；debug 工具最后一层 fallback |
| **用途** | `TEMPLATE-FUNCTIONS.md` 里 vector/map 的打印；`mint` 的 friend `<<` |
| **何时用** | 自定义 struct 要 debug；或 `__DEBUG_TOOL.h` 未 `REGISTER_REFLECT` 时的备选 |

#### B4. `freopen`

| 项 | 内容 |
|----|------|
| **为什么** | 不改编译命令，运行时把 stdin/stdout 指到文件 |
| **解决什么** | 本地测大样例、保存 debug 输出到 err.txt |
| **何时用** | 本地；**交 OJ 前删除或 `#ifdef LOCAL` 包住** |

---

### 模块 C：宏（你处于「使用者」，建议升级到「能读」）

#### C1. `#define` 与 `#x` 字符串化

```cpp
#define dbug(x) _dbug(#x, x)
// debug(vec) 展开后 #vec 变成 "vec" 这个字符串
```

| 项 | 内容 |
|----|------|
| **为什么** | 编译期文本替换；CP 里快速写 debug |
| **解决什么** | 打印「变量名 + 值」而不手写 `"vec", vec` |
| **风险** | 无类型检查；多语句宏要用 `do { ... } while(0)` |
| **何时用** | 短小的 LOCAL 开关；复杂逻辑优先用 **inline 函数 / 模板** |

#### C2. 宏拼接 `DBG_CAT(a, b)` → `a##b`

| 项 | 内容 |
|----|------|
| **为什么** | 根据参数个数选 `DBG_MAP_1` / `DBG_MAP_2` … |
| **解决什么** | `debug(a, b, c)` 一次展开成多行打印 |
| **用途** | `__DEBUG_TOOL.h` 核心；你 **会用 debug() 即可**，实现可后学 |
| **何时用** | 几乎只有写 **通用 debug 库** 时才需要自己写 |

#### C3. `REGISTER_REFLECT(Type, x, y)`

```cpp
// C++ 运行时不知道 struct 有哪些成员名；宏在编译期生成「访问 x,y 并带上名字字符串」的代码
REGISTER_REFLECT(Node, x, y)
```

| 项 | 内容 |
|----|------|
| **为什么** | 语言无内置反射（C++26 前） |
| **解决什么** | `Node { x: 1, y: 2 }` 这种可读 debug |
| **何时用** | 自定义 struct 且成员 ≤10；嵌套 struct 每个类型注册一次 |

---

### 模块 D：模板（你：会抄；建议：理解「一个模板 N 个类型」）

#### D1. 函数模板

```cpp
template<typename T>
void _dbug(const char* name, const T& x) { ... }
// 编译器看到你传 vector<int>、int 时会各生成一份函数（实例化）
```

| 项 | 内容 |
|----|------|
| **为什么** | 同逻辑多种类型，避免写十遍 overload |
| **解决什么** | `operator<<` 对 `vector<T>` 任意 T 成立 |
| **何时用** | 容器打印、max/min 泛型、线段树 `Info/Tag` |

#### D2. 类模板

```cpp
template<typename Info, typename Tag>
class SegmentTree { ... };
// Info/Tag 是你定义的「结点信息」和「懒标记」协议
```

| 项 | 内容 |
|----|------|
| **为什么** | 线段树骨架固定，区间语义随题变 |
| **解决什么** | 换题只改 `apply / operator+ / empty` |
| **你的下一步** | 亲手填完一份 `Info::apply` 和 `operator+`，比再抄十道题更有用 |

#### D3. `if constexpr`（C++17）

```cpp
if constexpr (is_map_like<D>::value) { /* 按 map 打 */ }
else if constexpr (is_iterable<D>::value) { /* 按 vector 打 */ }
// 假分支在编译期直接丢弃，不会生成错误代码
```

| 项 | 内容 |
|----|------|
| **为什么** | 普通 `if` 在模板里两个分支都要能编译 |
| **解决什么** | `print_val` 一条模板走多种类型 |
| **何时用** | 泛型工具库；CP 题内 **很少必要** |

#### D4. SFINAE / `type_traits`（进阶）

```cpp
// 问：T 有没有 mapped_type 成员？有则当 map 处理
is_map_like<T, void_t<typename T::mapped_type>>
```

| 项 | 内容 |
|----|------|
| **为什么** | 编译期「类型问答题」 |
| **解决什么** | 不写 ten 个 `operator<<` overload |
| **何时用** | 读 `__DEBUG_TOOL.h`、看 std 源码；**短期可不学写** |

---

### 模块 E：STL 容器（TEMPLATE 里已有，补「为什么选它」）

| 容器 | 为什么有 | 解决什么 | 何时用 | 注意 |
|------|----------|----------|--------|------|
| `vector` | 连续内存动态数组 | 随机访问、末尾增删 | 默认首选序列 | 中间插入慢 |
| `map` | 红黑树键值对 | 有序、按 key 查 | 需要有序或 lower_bound | O(log n) |
| `unordered_map` | 哈希表 | 平均 O(1) 查 | 只关心存在性、不要求序 | 常数大、可被 hack |
| `set` | 有序集合 | 去重 + 有序遍历 | 动态有序集合 | 无 `[]` |
| `multiset` | 允许重复 key | 第 k 小、多重计数 | 可重复元素有序集合 | |
| `pair` / `tuple` | 轻量聚合 | 返回两个以上值 | Dijkstra 存 `{v, dis}` | |
| `priority_queue` | 堆 | 每次取最值 | Dijkstra、合并果子 | 默认大根堆 |
| `deque` | 双端队列 | 两端 O(1) | 单调队列、BFS 层序 | |
| `array` | 固定长栈数组 | 避免 vector 堆分配 | 小固定长度 | |

---

### 模块 F：你已掌握的算法模板（补「选型」）

| 结构/算法 | 解决什么问题 | 何时选它 |
|-----------|--------------|----------|
| DSU | 动态连通性 | 合并集合、判环、Kruskal |
| 带权 DSU | 结点间相对关系 | 种类并、偏移量 |
| 回滚 DSU | 可撤销合并 | 离线 + 时间轴 |
| BIT | 单点改 + 前缀和 | 比线段树常数小、代码短 |
| 线段树 + lazy | 区间改 + 区间问 | 区间加、区间最值/和 |
| 主席树 | 历史版本 / 区间第 k | 可持久化、静态区间 k th |
| 分块 | 平衡暴力与数据结构 | n,m 不大或操作杂 |
| ODT | 区间赋值 + 值域随机 | CF 数据随机题 |
| ST 表 | 静态 RMQ | 不变数组区间最值 O(1) |
| Dijkstra | 非负权最短路 | 默认单源最短路 |
| SPFA | 最短路（含负权尝试） | 图小或特殊图；易 TLE |
| Floyd | 全源最短路 | n≤500 左右 |
| LCA | 树上最近公共祖先 | 树上路径、距离 |
| pb_ds | 增强 STL | 需要 order_of_key、可改堆 |
| 对拍 | 验证正确性 | WA 怀疑、新做法不确定 |

---

### 模块 G：工程向（你尚未系统学，建议路线）

#### G1. 多文件项目

```text
project/
  include/debug.hpp
  src/main.cpp
  src/solver.cpp
  CMakeLists.txt   // 或固定 .vscode/tasks.json
```

| 项 | 内容 |
|----|------|
| **为什么** | 单文件 3000 行不可维护 |
| **何时用** | debug 工具稳定后拆成库；与 Python bot 共存的 CF 工具集 |

#### G2. RAII 与智能指针

```cpp
// 资源获取即初始化：出了作用域自动释放
unique_ptr<SegmentTree> st = make_unique<SegmentTree>(n);
```

| 项 | 内容 |
|----|------|
| **为什么** | 手动 `new/delete` 易泄漏、异常不安全 |
| **何时用** | 指针版线段树、长生命周期对象；CP 可继续栈上 `vector` |

#### G3. 单元测试（GoogleTest / Catch2）

| 项 | 内容 |
|----|------|
| **为什么** | 对拍是「黑盒」；单元测试是「白盒测函数」 |
| **何时用** | debug 库、数学函数、数据结构封装稳定后 |

---

### 模块 H：`__DEBUG_TOOL.h` 与旧 debug 头对比

| | 旧版（TEMPLATE-FUNCTIONS.md） | 新版 `__DEBUG_TOOL.h` |
|--|-------------------------------|------------------------|
| 容器 | 手写多个 `operator<<` | 一个 `print_val` 递归 |
| 结构体 | `DBG_STRUCT` 宏写 `<<` | `REGISTER_REFLECT` |
| 多变量 | `dbug` 一次一个 | `debug(a, b, c)` |
| 难度 | 较低，能看懂 | 较高，需模块 A～D 基础 |
| 建议 | 仍可作为 **入门理解** | 作 **长期主力**；分阶段读源码 |

---

## 六、推荐学习路线（12 周，业余）

### 第 1～2 周：P0 基础（不碰复杂宏）

| 天 | 内容 | 实践 |
|----|------|------|
| 1 | 编译四步、`-DLOCAL` | 故意去掉 LOCAL 看报错 |
| 2 | cout/cerr、freopen | debug 打 cerr，答案打 cout |
| 3 | 引用、`const T&` | 写 `void show(const vector<int>& v)` |
| 4 | 模板函数 | 自己写 `T my_max(T a, T b)` |
| 5 | operator<< | 给一个 struct 手写 `<<` |
| 6～7 | 读 `print_val` 203～287 行 | 每类型在 TEST 里试 `debug()` |

### 第 3～4 周：板子「真会」

- 填完 **一份** 线段树 `Info/Tag`（区间加、区间和）  
- 手写 BIT、DSU **不看模板** 各一遍  
- 读 `REGISTER_REFLECT` + 试 2 个嵌套 struct  

### 第 5～8 周：小工程

- 把 `__DEBUG_TOOL.h` + `DEBUG-TOOL-TEST.cpp` 固定为独立 mini 项目  
- 学 `CMake` 或巩固 `tasks.json`（`-DLOCAL`、include path）  
- 可选：用 Python 写 CF 查询（`cf_service.py`）练 **另一种工程形态**  

### 第 9～12 周：进阶（选修）

- 移动语义 / `unique_ptr`  
- 读 `is_map_like` 一段 SFINAE  
- 一个 GTest 测 `print_val` 行为  

---

## 七、学习方向推荐（结合你现状）

1. **主线 A（CP 继续强化）**  
   把 TEMPLATE 里 **每个 DS 手写一遍** → 模板从「抄」变「改」。

2. **主线 B（读懂自己的工具）**  
   以 `__DEBUG_TOOL.h` 为教材，**只啃 `print_val` + `REGISTER_REFLECT`**，宏计数最后看。

3. **主线 C（工程入门，与 Python 并行）**  
   `cf_service.py`：模块、async、CLI——和 C++ 工程 **不冲突**，反而形成「算法 C++ + 工具 Python」分工。

4. **不建议现在做**  
   - 啃 STL 源码全集  
   - 学模板元编程写库  
   - 用 C++ 写大型 Web 后端（投入产出对你现阶段低）  

---

## 八、自测：你是否「真的掌握」某知识点

| 问题 | 能答「是」= 掌握 |
|------|------------------|
| `LOCAL` 没定义时，`debug()` 为什么报错？ | |
| `cout` 和 `cerr` 交题时差别？ | |
| 线段树 lazy 为什么要 `push` 再递归？ | |
| `REGISTER_REFLECT` 和手写 `operator<<` 各省什么？ | |
| `debug(vec)` 里 vector 的元素怎么被打印出来的？（递归） | |
| 对拍 WA 时你的排查顺序？ | |

---

## 九、文档与代码注释索引

| 文件 | 作用 |
|------|------|
| `templates/TEMPLATE-FUNCTIONS.md` | 你已会能力的 **清单与板子** |
| `notes/CPP-LEVEL-AND-ROADMAP.md` | 本文：**水平 + 百科 + 路线** |
| `source/__DEBUG_TOOL.h` | 文件头有 **短注释 + 指向本文** |
| `source/DEBUG-TOOL-TEST.cpp` | debug 功能试跑样例 |

---

*最后更新：对照 `TEMPLATE-FUNCTIONS.md` 全量梳理；评估刻意保守，便于你按真实缺口补课。*
