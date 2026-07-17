#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, ans = 0;
vector<int> row_mask;
int full_mask;

void dfs(int row, int col, int diag1, int diag2) {
    if (row == n) {
        ans++;
        return;
    }
    int conflict = col | diag1 | diag2;
    int pos = row_mask[row] & (~conflict) & full_mask;
    if (!pos) return;
    while (pos) {
        int p = pos & -pos; // 取最低位1
        pos &= pos - 1;     // 清掉最低位1
        dfs(row+1, col|p, (diag1|p)<<1, (diag2|p)>>1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // 关闭同步，加速输入，必加！
    cout.tie(0);
    cin >> n;
    full_mask = (1 << n) - 1;
    row_mask.resize(n, 0);
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        int mask = 0;
        for (int j = 0; j < n; j++) {
            if (s[j] == '.') mask |= 1 << j;
        }
        row_mask[i] = mask;
    }
    dfs(0, 0, 0, 0);
    cout << ans << endl;
    return 0;
}