// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;

int lcm(int a , int b) { 
  return a / __gcd(a , b) * b ; 
} 

void solve() { 

  int n, m, a, b; cin >> n >> m >> a >> b;
  bool f = (
    __gcd(n, a) == 1 and
    __gcd(m, b) == 1 and
    __gcd(n, m) <= 2
  );

  cout <<  (f ? "YES" : "NO") << endl; 
}

/*
想到很简单的一个策略

其实就是对于所有的 k1 * a % n 能否构成一个排列呢
对于所有的 k2 * b % m 能否构成一个排列呢 我确实是想到了这里

同时 这两个排列按照出现顺序一直组合 能否凑出所有的数对
这个过程中是不能出现数对有重复性的
不能存在 新组合出来的数对是已经存在过的数对

对于一个 a 生成的排列 长度为 n 对于一个 b 生成的排列 长度为 m

对于一个 环形数组长度 为 n 来说
从 1 出发步长为 a, 
要么生成一个固定的序列 比如 a == 2, n == 8
生成的就是 1 3 5 7 1 3 5 7
要么一定会生成一个排列 1 到 n 的排列

想要生成这样的一个排列 要确保 gcd(a, n) == 1 
我们可以证明一下

当前位置 pos == (k * a) mod n
可以知道的是 如果有 (k * a) === a (mod n) 的时候 即出现循环
也就是位置的序列长度为 k 
对于一个排列 显然我们希望 k == n
也就是对于 k (k <= n) 来说 一定不会出现 (k * a) === a(mod n)
同时 当 k * a == lcm(a, n) 的时候一定会出现 k * a === a (mod n)
所以 k * a 一定是等于 lcm(a, n) 的 同时我们希望这个最小的 k == n
所以 a 和 n 一定是互质的

其次我们的两个排列要互相匹配 
也就是这样的 :
1 p1 p1 p2 p2 p3 p3 p4 p4
1 1 k1 k1 k2 k2 k3 k3 k4 
or
1 1 p1 p1 p2 p2 p3 p3 p4 
1 k1 k1 k2 k2 k3 k3 k4 

首先去掉前面的共同的 1
就变成 任意一个排列的两倍为单位 在前面加个 1 
我们可以注意到的是 我们已经规定了一个排列的起始点一定是 1 
也就是说本来好似
p == 1, 2, 3, 4, 5
现在变成 p == 1, 1, 2, 2, 3, 3, 4, 4, 5, 5
其实本质上还是相等于 2 * n 和 2 * m 相匹配 下一次出现出现过的数对 我们也希望是 n * m 次配对之后
所以我们希望 gcd(2 * n, 2 * m) == 1
即 gcd(n, m) <= 2
*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  #ifdef GK
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
  #endif 

  // cout << fixed << setprecision(6);

  int tt , CNT = 0; cin >> tt;
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0;
}