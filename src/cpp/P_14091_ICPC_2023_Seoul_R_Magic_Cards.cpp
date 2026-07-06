// @Author : GoryK
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "__DEBUG_TOOL.h"
#endif 

#define int int64_t
#define endl "\n"

const int mod = 1e9 + 7; 
const int N = 2e7 + 10;

int n, k, m, f, cnt_node;
int val[N], t[N][2];

template<size_t N>
std::bitset<N> bitset_add(const std::bitset<N>& a, const std::bitset<N>& b) {
  std::bitset<N> result;
  bool carry = false;
  
  for (size_t i = 0; i < N; i++) {
    bool bit_a = a[i];
    bool bit_b = b[i];
    
    // 当前位结果 = a ^ b ^ carry
    result[i] = bit_a ^ bit_b ^ carry;
    
    // 计算进位 = (a & b) | (carry & (a ^ b))
    carry = (bit_a & bit_b) | (carry & (bit_a ^ bit_b));
  }
  
  return result;
}

void insert(string s, int num) {
  int p = 0;
  for(int i = 0; i < k; i ++) {
    int dig = s[i] - '0';
    if (!t[p][dig]) t[p][dig] = ++cnt_node;
    p = t[p][dig];
  }
  val[p] = num; 
}

int query(string s) {
  int p = 0;
  for(int i = 0; i < k; i ++) {
    int dig = (s[i] == 'Y' ? 1 : 0);
    if (!t[p][dig]) return 0;
    p = t[p][dig];
  }
  return val[p];
}

void solve() { 
  cin >> n >> k >> m >> f;
  set<int> s; for(int i = 1; i <= n; i ++) s.insert(i);
  vector<string> vec(n + 1, string(k + 1, '0')); 
  for(int i = 1; i <= k; i ++) {
    for(int j = 1; j <= m; j ++) {
      int num; cin >> num;
      vec[num][i] = '1';
    }
  }

  unordered_map<string, int> ump;
  for(int i = 1; i <= n; i ++) ump[vec[i]] ++;
  for(int i = 1; i <= n; i ++) {
    if (ump[vec[i]] < 2) {
      insert(string(vec[i].begin() + 1, vec[i].end()), i);
    } else {
      insert(string(vec[i].begin() + 1, vec[i].end()), 0);
    }
  }

  for(int i = 1; i <= f; i ++) {
    string q; cin >> q;
    cout << query(q) << endl;
  }
}

/*

*/

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // cout << fixed << setprecision(6);

  // int tt , CNT = 0; cin >> tt; 
  // while(tt -- && ++CNT) 
    // cout << "TEST CASE : " << CNT << endl,
    solve();
  
  
  return 0;
}