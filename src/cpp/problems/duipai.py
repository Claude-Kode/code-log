import subprocess
import random
import sys
import os

# 生成随机测试数据
def generate_test():
    n = random.randint(1, 10)
    a = []
    for _ in range(n):
        # 生成1-100之间的随机数
        a.append(random.randint(1, 100))
    return n, a

# 运行你的C++程序
def run_your_code(input_data):
    with open("input.txt", "w") as f:
        f.write("1\n")  # 一组测试
        f.write(f"{input_data[0]}\n")
        f.write(" ".join(map(str, input_data[1])) + "\n")
    
    # 编译并运行你的代码
    compile_result = subprocess.run(["g++", "-std=c++17", "-O2", "your_code.cpp", "-o", "your_code"], 
                                    capture_output=True, text=True)
    if compile_result.returncode != 0:
        print("编译错误:", compile_result.stderr)
        return None
    
    result = subprocess.run(["./your_code"], stdin=open("input.txt", "r"), 
                           capture_output=True, text=True)
    return result.stdout.strip()

# 运行AC代码
def run_ac_code(input_data):
    with open("input.txt", "w") as f:
        f.write("1\n")
        f.write(f"{input_data[0]}\n")
        f.write(" ".join(map(str, input_data[1])) + "\n")
    
    compile_result = subprocess.run(["g++", "-std=c++17", "-O2", "ac_code.cpp", "-o", "ac_code"], 
                                    capture_output=True, text=True)
    if compile_result.returncode != 0:
        print("AC代码编译错误:", compile_result.stderr)
        return None
    
    result = subprocess.run(["./ac_code"], stdin=open("input.txt", "r"), 
                           capture_output=True, text=True)
    return result.stdout.strip()

# 你的代码
your_code_cpp = """
#include <bits/stdc++.h>
using namespace std;

#define int int_fast64_t
#define endl "\\n"

const int mod = 1e9 + 7; 
const int N = 1e6 + 10;

int fac = 0;

vector<int> vis;
vector<int> pr;

vector<int> prime(int n) {
  vector<int> vis(N , 0) , pr ; 
  for ( int i = 2 ; i <= n ; i ++ ) {
    if( !vis[i] ) pr.push_back( i ) ;  
    for ( const auto &j : pr ) {
      if (i * j > n) break ; 
      vis[i * j] = 1 ; 
      if (i % j == 0) break ; 
    }
  }
  return vis; 
}

vector<int> primes(int n) {
  vector<int> vis(N , 0) , pr ; 
  for ( int i = 2 ; i <= n ; i ++ ) {
    if( !vis[i] ) pr.push_back( i ) ;  
    for ( const auto &j : pr ) {
      if (i * j > n) break ; 
      vis[i * j] = 1 ; 
      if (i % j == 0) break ; 
    }
  }
  return pr; 
}

pair<int, int> prime_factor(int a, vector<int>& pr) {
  set<int> factors;
  for (const auto &x : pr) if(a % x == 0) {
    while (a % x == 0) factors.insert(x), a /= x, fac = x;
    if ( a < x ) { if (a > 1) factors.insert(a); break; }
  } 
  return {factors.size(), *factors.begin()};
}

void solve() { 
  int n; cin >> n;
  vector<int> vec(n + 1);
  for(int i = 1; i <= n; i ++) {
    cin >> vec[i];
  }

  if (is_sorted(vec.begin() + 1, vec.end())) {cout << "Bob" << endl; return; }

  vector<int> b(n + 1); pair<int, int> res;
  for(int i = 1; i <= n; i ++) {
    if (vis[vec[i]] ) {
      auto res = prime_factor(vec[i], pr);
      if (res.first == 1) vec[i] = res.second;
      else vec[i] = INT_MAX;
      
    }
  }

  // cout << "VEC: ";
  // for(int i = 1; i <= n; i ++) cout << vec[i] << ' ';
  // cout << endl;

  if (is_sorted(vec.begin() + 1, vec.end())) cout << "Bob" << endl; 
  else cout << "Alice" << endl; 
}

signed main() {
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  
  vis = prime(N - 10);
  pr = primes(N - 10);

  vis[1] = 0;

  int tt , CNT = 0; cin >> tt;
  while(tt -- && ++CNT) 
    solve();
  
  return 0;
}
"""

# AC代码
ac_code_cpp = """
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

int primebase(int x) {
    set<int> s;
    for (int i = 2; i*i <= x; i++) {
        while (x % i == 0) {
            s.insert(i);
            x /= i;
        }
    }
    if (x > 1) s.insert(x);
    if (s.size() > 1) return -1;
    if (s.size() == 0) return 1;
    return *s.begin();
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    
    // solve
    vector<int> b(n);
    for (int i = 0; i < n; i++) b[i] = primebase(a[i]);
    if (is_sorted(all(a))) {
        cout << "Bob\\n";
    } else if (*min_element(all(b)) == -1) {
        cout << "Alice\\n";
    } else if (is_sorted(all(b))) {
        cout << "Bob\\n";
    } else {
        cout << "Alice\\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
"""

# 写入文件
with open("your_code.cpp", "w") as f:
    f.write(your_code_cpp)

with open("ac_code.cpp", "w") as f:
    f.write(ac_code_cpp)

# 对拍
print("开始对拍...")
found_diff = False
for test_case in range(1, 1001):
    n, a = generate_test()
    input_data = (n, a)
    
    your_output = run_your_code(input_data)
    ac_output = run_ac_code(input_data)
    
    if your_output != ac_output:
        print(f"测试用例 {test_case} 发现不一致！")
        print(f"输入: n={n}, a={a}")
        print(f"你的输出: {your_output}")
        print(f"AC输出: {ac_output}")
        found_diff = True
        break
    
    if test_case % 100 == 0:
        print(f"已测试 {test_case} 个用例...")

if not found_diff:
    print("前1000个随机测试用例全部通过！")
else:
    print("找到反例，请查看上面的输入。")