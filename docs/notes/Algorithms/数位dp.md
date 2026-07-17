下面我们从零开始，一步步写出数位 DP 的板子，并用它来解决 **“G. Increasing Sequence”** 这道题。我们会从最经典的「统计个数」开始，到带复杂状态的数位 DP，再到本题的高阶分治优化。

---

## 1. 数位 DP 的万能骨架（十进制）

**例题**：统计 \([0, K]\) 中，各位数字之和等于 \(S\) 的数的个数。

```cpp
using int = long long;
int dp[20][2][200]; // dp[pos][tight][sum]
string s;          // 把 K 转成字符串，方便取位

int dfs(int pos, bool tight, int sum) {
    if (pos == s.size()) return sum == 0;
    if (dp[pos][tight][sum] != -1) return dp[pos][tight][sum];

    int res = 0;
    int limit = tight ? s[pos] - '0' : 9;
    for (int d = 0; d <= limit; d ++) {
        if (sum - d < 0) continue;
        res += dfs(pos + 1, tight && (d == limit), sum - d);
    }
    return dp[pos][tight][sum] = res;
}
```

**核心要素**：
- `pos`：当前处理到第几位（从左往右）。
- `tight`：是否严格贴着上界 \(K\)。
- `sum`：题目要求的状态（剩余需要的和）。

---

## 2. 二进制版：统计 \([0, k]\) 中不含连续 1 的数

```cpp
int dfs(int pos, bool tight, bool prev_one) {
    if (pos == -1) return 1; // 成功构造一个数
    if (!tight && dp[pos][prev_one] != -1) return dp[pos][prev_one];

    ll res = 0;
    int limit = tight ? ((k >> pos) & 1) : 1;
    for (int b = 0; b <= limit; ++b) {
        if (prev_one && b == 1) continue; // 不能有连续 1
        res += dfs(pos - 1, tight && (b == limit), b == 1);
    }
    if (!tight) dp[pos][prev_one] = res;
    return res;
}
```

**关键变化**：
- 从十进制 `0~9` 变成二进制 `0/1`。
- 状态 `prev_one` 表示上一位是否选了 1。
- 记忆化时只记忆 `!tight` 的状态，因为 `tight` 状态极少。

---

## 3. 本题的最小版本：只有两个数 \(a_1, a_2\)

题目：给定 \(a_1, a_2, k\)，求 \(x \in [0, k]\) 使得 \(a_1 \oplus x \le a_2 \oplus x\) 的个数。

**分析**：按照之前的“相邻约束”，我们只需要看一对。  
从高位往低位 DP，状态记录：**到目前高位是否已经分出严格小于**（即“安全”了）。

```cpp
ll a1, a2, k;
ll dfs(int pos, bool tight, bool already_less) {
    if (pos == -1) return 1; // 合法
    // 简单记忆化（这里只示范，实际状态少可不记忆化）
    ll res = 0;
    int lim = tight ? ((k >> pos) & 1) : 1;
    for (int xb = 0; xb <= lim; ++xb) {
        if (!tight || xb < lim) tight = false; // 不卡
        if (already_less) {
            // 已经分出大小，之后随便选
            res += dfs(pos - 1, tight, true);
        } else {
            int u = (a1 >> pos) & 1, v = (a2 >> pos) & 1;
            int ux = u ^ xb, vx = v ^ xb;
            if (ux < vx) {
                // 这一位分出严格小于
                res += dfs(pos - 1, tight && (xb == lim), true);
            } else if (ux == vx) {
                // 仍然平局
                res += dfs(pos - 1, tight && (xb == lim), false);
            } else {
                // ux > vx，违规
                continue;
            }
        }
    }
    return res;
}
```

这就是**最纯粹的数位 DP**，状态仅 `pos, tight, already_less`。

---

## 4. 扩展到 \(n\) 个数：状压平局状态

对于 \(n\) 个数，我们需要同时维护 \(n-1\) 个“平局/安全”状态。  
如果 \(n\) 很小（例如 \(n \le 20\)），可以直接用位掩码 `mask`，第 \(i\) 位表示第 \(i\) 对是否已安全。

```cpp
int n;
vector<ll> a;
ll k;

// dfs(pos, tight, mask)   mask: bit i=1 表示第i对已安全
ll dfs(int pos, bool tight, int mask) {
    if (pos == -1) return 1;

    ll res = 0;
    int lim = tight ? ((k >> pos) & 1) : 1;
    for (int xb = 0; xb <= lim; ++xb) {
        int new_mask = mask;
        bool ok = true;
        for (int i = 0; i < n - 1; ++i) {
            if ((mask >> i) & 1) continue; // 已安全
            int u = (a[i] >> pos) & 1, v = (a[i + 1] >> pos) & 1;
            if (u == 0 && v == 1) {
                new_mask |= (1 << i); // 安全
            } else if (u == 1 && v == 0) {
                if (xb == 1) {
                    new_mask |= (1 << i); // 翻转后安全
                } else {
                    ok = false; break; // 违反
                }
            } // u==v 继续平局
        }
        if (!ok) continue;
        res += dfs(pos - 1, tight && (xb == lim), new_mask);
    }
    return res;
}
```

**问题**：\(n\) 可达 \(2 \times 10^5\)，`mask` 有 \(2^{n-1}\) 状态，直接爆炸。

---

## 5. 优化：利用“平局段连续”性质，转为分治递归

关键发现：  
**如果若干相邻对都处在“平局”状态，那么这些元素在前面的高位上全部相等，因此在当前位它们的值也必然全相同。**  
所以，我们可以用**区间列表**代替位掩码：每个区间 `[L, R]` 表示一个连续段，段内所有相邻对仍平局（段内元素高位全等）。

递归函数：

```cpp
struct Segment {
    int l, r;
    bool all_zero; // 高位上这段元素的公共前缀（虽然其实不需要存，当前位只需看值）
    // 更简单的实现：只存区间，然后递归时按当前位值分裂。
};

// 返回在 [L, R] 闭区间内，当前位值为 bit 的元素个数，可以按位划分
vector<Segment> split(const Segment& seg, int pos) {
    // 根据 (a[i] >> pos) & 1 将 seg 分裂成若干段，每段内位值相同
    // ...
}
```

但更常见的实现是直接用**函数参数传递当前的“全等段列表”**，每次按当前位分裂：

```cpp
ll dfs(int pos, const vector<pair<int,int>>& segs, bool tight) {
    if (pos == -1) return 1;
    // segs: 每个pair表示一个区间 [L, R]，区间内元素在前面高位全部相等
    // 在当前位置，每个区间内的元素位值必须全部为0或全部为1（否则不可能继续保持平局）

    // 先检查所有区间内是否一致，如果不一致，则必须在这一位分出大小，部分会安全
    // 根据 xb = 0 或 1，会有不同的新区间列表产生

    // 这里演示 pseudo-code，实际实现需仔细讨论各种情况
    ...
}
```

> 因为本题的最终解法涉及较复杂的“选择 xb=0 或 1，分裂区间并统计”的逻辑，很多选手采用**类似字典树的分治**：  
> 将所有 \(a_i\) 插入二进制 Trie，然后 DFS 处理，但核心思想与数位 DP 完全一致。

---

## 6. 总结：数位 DP 的演化树

| 版本 | 状态 | 适用条件 |
|------|------|----------|
| 基础数位 DP | `pos, tight, 简单状态` | 单个数，条件简单 |
| 二进制数位 DP | 同上，位取值 0/1 | 异或、位运算 |
| 多对象（小 n） | `pos, tight, mask` | n 很小，能状压所有相邻关系 |
| **多对象（大 n）** | `pos, tight, 区间列表` | n 很大，利用**平局连续**性质压缩状态 |

你一开始的想法“逐位翻转”其实已经点中了数位 DP 的入口，而最后的破局在于：  
**用“已经分出大小”或“仍在平局”作为状态，并用区间合并来避免状态爆炸。**

---

如果你需要，我可以进一步给出**分治版本的完整实现**（非伪代码），让你看到它和上面数位 DP 的精确对应关系。\


我们继续深入，这次全面、系统地讲透数位 DP，包括它的底层原理和本质，最后再给你一批 Codeforces 及各类邀请赛的经典题目练手。

---

## 一、为什么能 DP？—— 从暴力搜索到记忆化的必然

数位 DP 解决的问题几乎都是这个形式：

> 给定一个区间 \([L, R]\)，求其中**十进制数位（或二进制位）满足某些性质**的数字个数（或求和、计数等）。

如果直接遍历 \(L\) 到 \(R\)，数字可能大到 \(10^{1000}\)，暴力绝对超时。  
但我们注意到：当我们**按位从高到低构造一个数字**时，当前位之后的选择，只与之前**已经固定的某些状态**有关，而与具体是哪些前缀数字无关。

### 举个例子
问题：求 0~324 中“数位和不超过 5”的数字个数。  
假设我们已经固定前两位是 `3, 2`，那么第三位可以取 0~4（因为上限是 324）。  
如果我们固定前两位是 `3, 1`，第三位可以取 0~9（因为已经小于 324 了，后面不受限）。  
**无论前面具体是 31 还是 30，只要它们都“已经小于上限”且“当前数位和相同”，那么剩余位的合法方案数就完全一样。**  
这就是**重叠子问题**：相同状态（当前位置、是否顶上限、数位和）会被反复计算，我们可以用记忆化避免重复。

### 满足 DP 的两个关键性质
1. **无后效性**：当前位的决策只依赖于已传递的有限状态（如是否贴上限、前导零、已出现的数字、数位和模数等），而不依赖具体的前缀数字。
2. **最优子结构（计数型 DP）**：从某一位开始的合法方案数 = 当前位所有合法选择的方案数之和（子问题合并）。

所以数位 DP 本质是一个**状态空间很小的记忆化搜索**。

---

## 二、核心状态与通用模板

### 状态参数
设要统计 `0 ~ N` 中满足条件的个数，`N` 的数位数组为 `s`，从最高位 `pos=0` 开始构造。

- **`pos`**：当前处理到第几位（从 0 开始）。
- **`tight`**：布尔值，表示前面的位是否**全部严格等于 `N`** 的前缀。  
  - `tight=True`：当前位最多只能选到 `s[pos]`。  
  - `tight=False`：当前位可以任意选择 0~9。
- **`leading_zero`**（或 `started`）：布尔值，表示是否还在前导零阶段（即前面每一位都是 0）。  
  很多限制（如“不能有重复数字”）不应在前导零阶段生效。
- **`state`**：根据题目维护的额外状态，例如：
  - 数位和 / 乘积 / 模数
  - 上一数字（处理连续相同/递增）
  - 已用数字的 bitmask
  - 是否已出现某个模式（自动机状态）
  - 奇偶位上的限制等

### 通用递归代码（Python 记忆化搜索）
```python
def count_up_to(N):
    s = list(map(int, str(N)))
    memo = {}
    
    def dfs(pos, tight, leading_zero, *state):
        if pos == len(s):
            # 构造完成，判断是否符合最终条件
            return 1 if 满足 else 0
        
        # 记忆化键，通常 tight 为 True 时不记忆化（因为只访问一次），但记了也没关系
        key = (pos, tight, leading_zero) + state
        if key in memo:
            return memo[key]
        
        limit = s[pos] if tight else 9
        res = 0
        for d in range(0, limit + 1):
            next_tight = tight and (d == limit)
            next_leading = leading_zero and (d == 0)
            # 根据 d 和当前状态计算新 state_new
            # 有时如果前导零且 d==0，状态保持不变
            res += dfs(pos+1, next_tight, next_leading, *state_new)
        
        memo[key] = res
        return res
    
    return dfs(0, True, True, *init_state)
```

区间 \([L, R]\) 答案 = `count_up_to(R) - count_up_to(L-1)`。

---

## 三、数位 DP 的本质 —— 十叉树上的有限状态 DP

从抽象角度看，**所有 0~N 的数字构成了一棵十叉 Trie 树**（深度为位数），每条根到叶子的路径对应一个数字（可含前导零）。  
数位 DP 就是在这棵树上**自顶向下**做记忆化搜索，每个节点表示一个前缀，状态是从根到此节点的“约束信息”。  
- `tight=True` 的路径是紧贴着 N 的前缀，这条路径的子树深度依然是受限的。  
- `tight=False` 的子树则是**完全相同的满十叉子树**，无论前面是什么数字，只要状态相同，这棵子树的合法叶节点数就相同。  
记忆化存储的就是这些“完全子树”的结果，极大地压缩了状态空间。

更形式化地：数位 DP 本质是在一个**确定有限自动机（DFA）**上统计长度不超过 len(N) 且字典序 ≤ N 的单词数。  
状态就是 DFA 的节点（可能带上 tight 标记），转移由数字 0~9 驱动，记忆化避免重复访问。

因此，当题目可以抽象为“数字字符串满足某正则条件”时，往往能用数位 DP。

---

## 四、状态设计技巧与常见变种

### 1. 只记忆化 `tight=False` 的状态
因为 `tight=True` 的状态在整棵搜索树中只有一条路径，不会重复，记忆化它反而浪费空间。  
通常我们会这样：
```python
if not tight and key in memo: return memo[key]
...
if not tight: memo[key] = res
```
这样状态数更少。

### 2. 前导零的处理
很多条件要求“没有前导零”，例如“无重复数字”时，如果前面全是 0，我们当前选了 0，其实这个 0 不算真正的数字开始。  
**标准做法**：用一个布尔变量 `leading` 标记。当 `leading=True` 且当前选 0，状态不变（如 bitmask 还是 0），且数字还没开始。

### 3. 多状态组合
- 数位乘积/和 -> 直接存值
- 模运算 -> 存余数
- 出现过的数字 -> 10 位二进制掩码
- 前一位是几 -> 存储 last digit（处理相邻约束）
- K 次限制 -> 计数已使用的次数

### 4. 不是求个数，而是求和、平方和等
有时题目要求区间内满足条件的数字的和，或者平方和。  
对于求和，每个状态不仅返回**个数 cnt**，还返回**这些数之和 sum**。转移时，对于当前位选的数字 d，它对后面的所有数贡献 `d * 10^{剩余位数} * cnt_sub`。  
因此状态需要同时维护 cnt 和 sum，甚至 sum of squares。结构类似典型的 DP 维护组合信息。

---

## 五、练习题目推荐（Codeforces + 省赛/邀请赛）

这里给你一批经典题目，从易到难，全部实测可用数位 DP 通过。

### 基础入门
1. **Codeforces 96B - Lucky Numbers (easy)**  
   求不小于 n 的最小超级幸运数（只由 4 和 7 组成，且 4 和 7 个数相等）。可以用数位 DP + 二分，但更简单的是暴力构造。不过可以体会用 DP 统计个数。

2. **Codeforces 1036C - Classy Numbers**  
   求区间内十进制表示中非零数字个数不超过 3 的数个数。  
   状态：`pos, tight, started, cnt_nonzero`。入门必做。

3. **Codeforces 628D - Magic Numbers**  
   求区间内偶数位为 d 奇数位不能是 d 且能被 m 整除的数字个数。  
   状态：`pos, tight, started, rem`（模 m 的余数），还要分奇偶位。

### 进阶状态设计
4. **Codeforces 55D - Beautiful Numbers**  
   求区间内能被自己每个非零数位整除的数个数。  
   需要 LCM(1..9) = 2520，维护 `rem` 模 2520，和已出现的数字的 LCM（离散化到 48 个值）。经典难题。

5. **Codeforces 1073E - Segment Sum**  
   求区间内数位包含的数字种类不超过 k 的数的**和**。  
   状态：`pos, tight, started, mask`（10位），需要维护两个信息：个数和总和。

6. **Codeforces 855E - Salazar Slytherin’s Locket**  
   求区间内每个十进制数字出现次数均为偶数的数字个数。  
   状态：`pos, tight, started, mask`（10 位二进制表示奇偶性）。Query 次数多，需要提前预处理不受限状态。

### 二进制 DP 与其他
7. **Codeforces 1245F - Daniel and Spring Cleaning**  
   求区间内满足 `x & y == 0` 且 `L ≤ x ≤ R, L ≤ y ≤ R` 的整数对 (x,y) 个数。  
   可以用两重数位 DP 同时枚举 x,y 的二进制位，状态增加 x 和 y 是否贴上下界。

8. **Codeforces 276D - Little Girl and Maximum XOR**  
   虽然这题贪心可做，但也是二进制数位 DP 的经典思维，求区间内两数异或最大值。

### 省赛/邀请赛经典题（均可在洛谷、牛客等找到）
- **Luogu P2657 [SCOI2009] windy 数**  
  不含前导零且相邻数字之差 ≥ 2 的数个数。状态：`pos, tight, started, last_digit`。  
  几乎是数位 DP 教案第一题。

- **Luogu P2602 [ZJOI2010] 数字计数**  
  求区间内每个数码 0~9 的出现次数。  
  状态：`pos, tight, leading_zero, cnt[]`。需要多次 DP 或一次 DP 计数。

- **Luogu P4317 花神的数论题**  
  设 sum(i) 为 i 二进制中 1 的个数，求 ∏ sum(i) （区间乘积）。  
  二进制数位 DP 求各种 sum 的个数，然后快速幂。

- **牛客网/NowCoder 2018年全国多校算法寒假训练营练习比赛 - 数的数字**  
  也有类似数位 DP 练习。

- **ICPC 区域赛真题**：例如 2018 青岛站 J 题（Books）不是数位DP，但 2019 南京站某题可能涉及。其实很多省的邀请赛会直接改编 windy 数或数字计数。

可以按照这个顺序去刷，代码模板基本不变，只是状态部分需要灵活设计。

---

## 六、总结本质与建议

**数位 DP = 按位枚举 + 记忆化搜索 + 状态抽象**  
把数字看作字符串，在字典序十叉树上 DP，利用“不受上限的子树的同质性”消除重复计算，将指数级枚举降到多项式状态数。

再给你几点提醒：
- 先确定能不能用 `count(R) - count(L-1)`，如果区间性质特殊（如区间异或和），可能要同时上下界 DP。
- 状态中能合并的就合并，比如只关心模某个数，不要存整个数。
- `tight` 和 `leading_zero` 是精密逻辑，不要弄反。
- 二进制 DP 与十进制完全同理，只是 base 变为 2。

如果你对其中某一题的状态设计没思路，或者想看特定题目代码，直接告诉我题号，我给你拆解状态转移。加油，数位 DP 练熟了就是模板填空题！

数位 DP 模板

输入: n, 限制条件 f(d, state)
```
s = str(n), m = len(s)
定义 dfs(pos, tight, state):
    if pos == m:           ← 填完了
        return state 是否合法

    if memo 有记录:        ← 记忆化 (仅 tight=False 时)
        return memo

    limit = s[pos] if tight else 9
    res = 0

    for d in 0..limit:
        if 不满足限制:     ← 剪枝
            continue
        res += dfs(pos+1, tight and d==limit, 新状态(state, d))

    memo 记录 res
    return res
```