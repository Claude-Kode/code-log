#include <bits/stdc++.h>
using namespace std;

#define int long long 

struct Info {
  // 1 尖尖向上 0 尖尖向下
  int dir;
  int le;
  int de;
  int re;
  int x;
  int y;
};


unordered_map<int, int> ump;
unordered_map<int, int> inv;
unordered_map<int, vector<int>> num;
unordered_map<int, int> sum;
unordered_map<int, set<int>> num_ex;

int dirs[3][2] = {{-1, 0}, {1, 1}, {1, 0}};

void solve() {
  int n; cin >> n;
  vector<vector<int>> vec(2 * n + 10, vector<int>(2 * n + 10));
  for (int i = 1; i <= n; i ++) {
    for (int j = 1; j <= 2 * i - 1; j ++) {
      cin >> vec[i][j];
    }
  }

  for (int i = 1; i <= n; i ++) {
    for (int j = 1; j <= 2 * i - 1; j ++ ) {
      cout << vec[i][j] << " \n"[j == 2 * i - 1];
    }
  }

  int tx, ty;
  cin >> tx >> ty;

  ump[7] = 1;
  ump[10] = 2;
  ump[13] = 3;
  ump[15] = 4;

  sum[1] = 7;
  sum[2] = 10;
  sum[3] = 13;
  sum[4] = 15;

  num[1] = {1, 2, 4};
  num[2] = {2, 3, 5};
  num[3] = {3, 4, 6};
  num[4] = {4, 5, 6};

  num_ex[1] = {1, 2, 4};
  num_ex[2] = {2, 3, 5};
  num_ex[3] = {3, 4, 6};
  num_ex[4] = {4, 5, 6};

  inv[1] = 5;
  inv[5] = 1;
  inv[2] = 6;
  inv[6] = 2;
  inv[3] = 4;
  inv[4] = 3;

  queue<Info> q; 
  // {
  //   deque<int> temp(num[vec[1][1]].begin(), num[vec[1][1]].end());
  //   // cout << vec[1][1] << "\n";
  //   for (int i = 0; i < 3; i ++) {
  //     q.push({0, temp[0], temp[1], temp[2], 1, 1});
  //     // cout << temp[0] << ' ' << temp[1] << ' ' << temp[2] << "\n";
  //     temp.push_front(temp.back());
  //     temp.pop_back();
  //   }
  // }
  auto temp = num[vec[1][1]];
  q.push({0, temp[0], temp[1], temp[2], 1, 1 });
  // cout << vec[1][1] << ' ' << vec[2][2] << "\n"; 

  int ans = INT_MAX;
  while (!q.empty()) {
    auto [d, l, e, r, x, y] = q.front();
    if (x == tx and y == ty) {
      ans = min(ans, d);
    }
    q.pop();

    cout << x << ' ' << y << "\n";

    cout << d << "\n";
    if (!(d & 1)) {

      int down = e;
      {
        int nx = x, ny = y - 1;
        if (!vec[nx][ny]) continue;
        // cout << nx << ' ' << ny << "\n";
        int nxt = vec[nx][ny];
        if (num_ex[nxt].count(l)) {
          q.push({d + 1, sum[nxt] - inv[down] - l, inv[down], l});
        }
      }

      {
        int nx = x + 1, ny = y + 1;
        cout << nx << ' ' << ny << "\n";
        if (!vec[nx][ny]) continue;
        int nxt = vec[nx][ny];
        cout << nxt << " \n";
        if (num_ex[nxt].count(down)) {
          q.push({d + 1, inv[r], down, inv[l], nx, ny});
        }
      }

      {
        int nx = x, ny = y + 1;
        if (!vec[nx][ny]) continue;
        // cout << nx << ' ' << ny << "\n";
        int nxt = vec[nx][ny];
        if (num_ex[nxt].count(r)) {
          q.push({d + 1, r, inv[down], sum[nxt] - r - inv[down], nx, ny});
        }
      }

    } else {
      int up = e;

      {
        int nx = x, ny = y - 1;
        if (!vec[nx][ny]) continue;
        // cout << nx << ' ' << ny << "\n";
        int nxt = vec[nx][ny];
        if (num_ex[nxt].count(l)) {
          q.push({d + 1, sum[nxt] - inv[up] - l, inv[up], l, nx, ny});
        }
      }

      {
        int nx = x, ny = y + 1;
        if (!vec[nx][ny]) continue;
        // cout << nx << ' ' << ny << "\n";
        int nxt = vec[nx][ny];
        if (num_ex[nxt].count(r)) {
          q.push({d + 1, r, inv[up], sum[nxt] - r - inv[up], nx, ny});
        }
      }

    }
  }

  cout << (ans == INT_MAX ? -1 : ans) << "\n";
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int tt = 1;
  // cin >> tt;
  while (tt --) {
    solve();
  }
}