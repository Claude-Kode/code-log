// @Author : GoryK
#include <bits/stdc++.h>
using namespace std ;

#define int long long
#define endl '\n'

const int mod = 1e9 + 7 ; 
const int maxn = 2e5 + 10 ;

struct pair_hash {
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2>& p) const {
    auto hash1 = hash<T1>{}(p.first) ;
    auto hash2 = hash<T2>{}(p.second) ;
    return hash1 ^ (hash2 << 1) ;
  }
} ;

void solve() { 

  int n ; cin >> n ; 
  vector<int> vec(n + 1) ; 

  for ( int i = 1 ; i <= n ; i ++) {
    cin >> vec[i] ; 
  }

  vector<int> del(n + 1); stack<int> st; 
  for (int i = 1; i <= n; i++) {
    while( !st.empty() && vec[st.top()] < vec[i] ) st.pop() ;
    st.push(i);
    del[i] += i - st.size();
  }

  while( !st.empty() ) st.pop();
  for (int i = n; i > 0; i--) {
    while( !st.empty() && vec[st.top()] < vec[i] ) st.pop() ;
    st.push(i) ;
    del[i] += n - i + 1 - st.size() ;
  }

  cout << *min_element(del.begin() + 1 , del.end()) << endl ;

}

/*

如果是区间 dp 的想法的话最大的元素是绝对不能删掉的
然后就可以缩小区间进行子问题的求解 代码量非常的少 很逆天但是是 n方的解法

这道题的On解法是贪心 , 有点牛逼 
可以知道最后的序列一定是一个单调递增或者单调递减的序列
我们可以用一正向的 dp 和一个反向的 dp 求解即可(从 mx 的位置向左右分别求最长递减子序列)
另一种方法是单调栈 , 其实单调栈的本质就是维护一个以当前元素为结尾的最大递增或者递减子序列 , 
由于是最大的元素向左向右求递减子序列 我们就从左到右求一个单调递增站
从右到左求一个单调递减栈
注意 , 单调栈实时的长度就是以当前元素为结尾的最大单调子序列的长度 , 所以可以很容易的求解出要删掉的元素
两个方向的数组合并一下就可以了

还有我一开始的想法还是线性dp那种为啥我想不到区间dp呢以后注意注意
如果不能单向的从一侧推导出另一侧 就考虑找锚点分隔开区间求解(锚点就是一定不会变的点) 
所以说这道题就是找最大值 , 因为最大值一定不会被删掉

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

  int tt ; cin >> tt ;
  while(tt --) solve() ;
  
  return 0 ;
}

// Functions : 

int fp( int x , int p , int mod) {
  int res = 1 , base = x ; 
  while ( p ) {
    if ( p & 1 ) (res *= base) %= mod ; 
    (base *= base) %= mod ; 
    p >>= 1 ;
  }
  return res ; 
}

int lcm(int a , int b) { return a / gcd(a , b) * b ; } 

int inv (int x , int mod) { return fp(x , mod - 2 , mod) ; }

void dedup(vector<int>& vec ) { 
  sort(vec.begin() + 1 , vec.end()) ;
  vec.erase(unique(vec.begin() , vec.end()) , vec.end()) ; 
}
