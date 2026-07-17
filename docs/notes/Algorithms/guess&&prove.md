# 本文件用于整理一些做题所得的原理和 trick 之类的
## 关于早期的 trick 请见 你的 work 文档, 做题记录思考和技巧

### 提取公共贡献 缩小问题, log求解
[26-钉耙杯-5-1004](https://acm.hdu.edu.cn/contest/problem?cid=1201&pid=1004)
另注本题可以纯手推公式解题
有一个结论 对于 $$f(n) = f(\frac{n}{2}) + \frac{n}{2} $$ 显然 
$$ f(n) = \sum_{1}^{\infty } \frac{n}{2 ^ {k}}  $$ 
形象的来说 相当于把 n 不停右移直到 0 为止, 所以我们可以想象 , 对于 n 里面为 i 的位置 , 在这个过程中会产生一个"拖影"
$$ n = 1000 $$ 
有 

$$  f(n) = 1000 + 100 + 10 +1 + 0$$
所以对于 n 里面所有 为 1 的位置的贡献即为
$$ 对于 n \ll j = 1, countibutionToSum = 2 ^ {j} - 1 $$
所以可以得到 
$$ f(n) = n - popcount(n) $$ 

当我们要计算
$$ \sum_{i = 1} ^ {n} f(i) = \sum_{i = 1} ^ {n} i + \sum_{i = 1} ^ {n} popcount(i)$$

我们只需要关注 popcount 如何快速求解即可 , 于是有公式
$$ \sum_{i=1}^n \text{popcount}(i) = \sum_{k=0}^{\lfloor \log_2 n \rfloor} \left( \left\lfloor \frac{n}{2^{k+1}} \right\rfloor \cdot 2^k + \max\left(0, (n \bmod 2^{k+1}) - 2^k + 1\right) \right) $$

我们可以理解为 每次对于我们所有的 $$ i \in n $$
我们统计最低位的 1 的个数, 然后所有的数统一右移
这样可以玩称一次问题缩减
从而变成了
$$ \sum_{i=1}^n \text{popcount}(i) = \sum_{k=0}^{\lfloor \log_2 n \rfloor} \sum_{i = 1} ^ {\frac{n}{2 ^ {k}} } (i \bmod 2) $$

我们进一步化简
$$ \sum_{i = 1} ^ {\frac{n}{2 ^ {k}} } (i \bmod 2) = \left \lceil \frac{\frac{n}{2 ^ {k}}}{2} \right \rceil $$ 

所以最后有公式
$$ \sum_{i=1}^n \text{popcount}(i) = \sum_{k=0}^{\lfloor \log_2 n \rfloor} \left \lceil \frac{\frac{n}{2 ^ {k}}}{2} \right \rceil $$ 
更严谨的 我们可以写作 
$$ S(n) = \sum_{k=0}^{\lfloor \log_2 n \rfloor} \left\lfloor \frac{n + 2^{k}}{2^{k+1}} \right\rfloor  $$

### 容斥原理
[26-钉耙杯-5-1006](https://acm.hdu.edu.cn/contest/problem?cid=1201&pid=1006)
一个很好的容斥原理的题目
具体的 对于容斥原理来说
$$ res = \sum_{T \in S , |T| \ne \emptyset }^{}  ⋂T * \left ( coef \right ) $$ 
具体的对于这道题来说 
$$ T⊆S,T\ne ∅  \sum coef(|T|) * {(x,y)∈⋂T∣a[x][y]≤∣T∣} $$ 

对于满足一定集合的交集的元素来说 一般会有一定的限制 , 就是这个
$$  {(x,y)∈⋂T∣a[x][y]≤∣T∣} $$ 

### 前缀异或值的规律 
题目链接 : [CF-2224-D](https://codeforces.com/contest/2225/problem/D)
符合下面的式子
我们定义函数 S(k) 
$$ S(k) = 1 \oplus 2 \oplus 3 ... \oplus n  $$ 
有规律 : 
$$ S(k) = 4 * \left \lfloor \frac{k}{4} \right \rfloor, (k \equiv 0 \bmod 4) $$

$$ S(k) = 1,  (k \equiv 1 \bmod 4) $$ 

$$ S(k) = 3 + 4 * \left \lfloor \frac{k}{4} \right \rfloor, (k \equiv 2 \bmod 4) $$

$$ S(k) = 0, (k \equiv 3 \bmod 4) $$

我们可以搭配函数来计算 : 
$$ 找最大的 k, k * mod + m \le lim $$ 

$$ k = ⌊\frac{lim - m}{mod}⌋ (显然 k 为非负整数) $$

$$ 由于 k \in [0, +\infty] , 所以有 cnt = k + 1$$

$$ 于是有 f(lim,m)=⌊\frac{lim−m}{mod}⌋+1 $$


```
int cnt(int lim, int m, int mod) {          
  if (lim < m) return 0; 
  return (lim - m) / mod + 1;
}
```

### 并查集通过单向合并制造跳跃指针 可以实现类似 ODT 的效果
[CF-920-F](https://codeforces.com/contest/920/problem/F)
本质上并查集就是创建一条无向边 那么我们只要按照固定的方向进行合并的话 相当于可以从一个点直接瞬移到他的父节点
实现了一种类似于条哦月至真的效果
感觉这个技巧还真的挺好的用的

### 观察到 把操作进行拆分之后只有固定的影响 


### mod 的转义
我们可以把数组转成 p 进制的数, 这样 mod p 就相当于取出最低位 
[sample](https://codeforces.com/gym/106289/problem/L)

### 鸽巢定理
破局之道 

### ^特性
```
popcount(a ^ b) & 1 = (popcount(a) + popcount(b)) & 1
a + b = a ^ b + 2 * a & b
a ^ b = (a | b) - (a & b) 
```
[sample](https://codeforces.com/gym/106570/problem/H )

### 解题总体思路
明白。浓缩如下：

**一切解题的本质：把问题从“坏的表示”强制转换为“好的表示”。**

核心元操作，只有五个：

1.  **解耦**：变量纠缠时，找不变量、势能，或它们的乘积/和，把两件事合成一件事。
2.  **显式划分**：用资源、位置等维度，把全局切成互不干扰的独立格子，遗忘历史。
3.  **同构翻译**：拒绝在原题模拟。问“这操作在边界/抵消/序的视角下，本质上是什么？”找到等价的新世界。
4.  **强制定死**：解耦不了，就强行定死一个变量，用外层枚举把耦合退化掉。
5.  **目标约束互换**：谁的范围小，谁就是新的状态维度。

你做题时的核心意识，就是在脑中循环这五条指令，直到问题塌缩成平凡结构。

我们可以注意到, ...之和...有关, 可以 dp 或者问题转化之类的
还有一个很重要的点就是单调性, 一个东西的单调性可以切换成另一个东西的单调性


### 素数猜想

x 以内的素数数量约等于 x / lnx


(两数之差可以被 gcd 整除)
质因数分解的 复杂度是 n ^ {1 / 2} / ln_{n} 的
其实也可以加个 n ^ {1 / 2}, 当做线性筛的复杂度

数位的本质是, 高位的最大影响, 比低位所有的最大影响加起来还大
耳机你只就是个很好的例子
10000 > 01111
这样理解是更容易的