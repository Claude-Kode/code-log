// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

vector<vector<int>> C;

vector<vector<int>> generate_c(int n) {
  vector<vector<int>> C(n + 1, vector<int>(n + 1, 0));
  for (int i = 0 ; i <= n ; i ++) { 
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j ++ ) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
  }
  return C;
}

int cmb(int n, int k) {
  if (k < 0 || k > n) return 0;
  return C[n][k];
}

void solve() { 

  int l, r; cin >> l >> r;

  auto get = [&](int n , int lim) -> int {
    int res = 0;
    for (int i = 0; i <= lim; i++) res += cmb(n, i) * pow(9, i);
    return res;
  }; 

  auto calc = [&](int x) -> int {
    string str = to_string(x);
    int n = str.size(), cnt1 = 3, res = 0;
    for (int i = 0; i < n; i ++) {
      if (str[i] == '0') continue;
      int len = n - i - 1;
      res += get(len, cnt1);
      cnt1--;
      if (cnt1 == -1) break; 
      res += get(len, cnt1) * (str[i] - '1');
    }
    return res;
  };

  cout << calc(r + 1) - calc(l) << endl; 

}

/*
dp 计算组合数
数位 dp

我们转换问题 
[l, r] == [0, r] - [0, l]

对于一个上界 x 我们从高到低遍历 , 
在固定一个数的前缀的情况下 , 如果当前位置是 0 , 那么为了确保后面生陈大哥数字一定小于x
我们不能改变这一位
对于当前数字不是 0 的情况下 , 我们可以改成比他小的数字

而这里面有两种分类讨论
第一种我们确定当前的数字就填 0 , 那么就是 len - 1个位置填 cnt 个数字
第二种我们确定当前数字不填 0 , 那么就是 当前数字可填的非 0 * len - 1个文职填写 cnt - 1 个数字

组合数的地推也是同理
对于第 n 个位置来说 
如果是一定选的 , 那么此时的方法数量等价于从 n-1 个里面选 k-1 个
如果一定不选 , 那么此时的方法数量等价于从 n-1 个里面选 k 个

也就是实际上我们可以转化成两种状态 选或者不选 , 这就是经典的 bianry-kanpsack 问题了

关键在于
第一 固定前缀 然后只需要管理后缀就可以保证数字一定小于等于上界
第二 由于数字的比较规则 , 如果前缀相同 , 只要高位更大后面的数字不用看这个数字一定是跟大哥啊的
第三 关注这个位置的状态 分两种情况讨论相加即可

*/

signed main() {
  
  std::ios::sync_with_stdio(false) ;
  std::cin.tie(nullptr) ;
  std::cout.tie(nullptr) ;
  
  #ifdef GK
    freopen("INPUT.txt", "r", stdin) ;
    freopen("OUTPUT.txt", "w", stdout) ;
  #endif 

  // cout << fixed << setprecision(6) ;
  C = generate_c(20);

  // cout << pow(9, 0) << pow(9, 1) << pow(9, 2) << pow(9, 3) << endl; 

  int tt , CNT = 0; cin >> tt;
  while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  return 0 ;
}


