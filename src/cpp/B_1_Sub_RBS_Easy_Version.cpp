// @Author : GoryK
// #pragma GCC optimize("Ofast,fast-math")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl '\n'

const int mod = 1e9 + 7; 
const int N = 2e5 + 10;
string temp;


void solve() { 

  int n; cin >> n >> temp;
  string s = " ", s += temp;


}

/*

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

#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        int n;
        string s;
        cin >> n >> s;
        vector<int> nx(n + 1, n + 1);
        vector<int> suf(n + 1, 0);
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == '(') nx[i] = i;
            else nx[i] = nx[i + 1];
            if(s[i] == '(') suf[i] += 1;
            suf[i] += suf[i + 1];
        }

        int ans = -1;
        for(int i = 0; i < n; i++){
            if(s[i] == ')' and nx[i] <= n){
                int ig = nx[i] - i;
                if(suf[nx[i] + 1] >= ig){
                    ans = max(ans, n - 2 * ig);
                }
            }
        }

        cout << ans << '\n';
    }
}        