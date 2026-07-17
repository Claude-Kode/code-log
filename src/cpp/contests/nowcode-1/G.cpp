#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
using db = long double;
void solve() {}
db ansx[300], ansy[300], ansz[300];
db dis(db x1, db y1, db z1, db x2, db y2, db z2) {
  return sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) +
               (z1 - z2) * (z1 - z2));
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cout << fixed << setprecision(9);

  int tt = 1;
  cin >> tt;
  while (tt--) {
    // solve();
    ll n;
    cin >> n;
    ll sum = n;
    ll k = 1;
    sum--;
    ansx[1] = 1;
    ansy[1] = 0;
    ansz[1] = 0;
    db x0 = 1;
    while (sum) {
      sum--;
      k++;
      if (k % 2 == 0) {
        x0 -= 0.011;
        db x1 = x0;
        db y1 = sqrtl((db)1 - x1 * x1);
        ansx[k] = x1;
        ansy[k] = y1;
        ansz[k] = 0;
      } else {
        db x1 = x0;
        db y1 = sqrtl((db)1 - x1 * x1);
        ansx[k] = x1;
        ansy[k] = -y1;
        ansz[k] = 0;
      }
    }
    sum = n;
    ll g = 0;
    x0 = 0;
    db y0 = 0;
    db z0 = 0;
    while (sum) {
      sum--;
      g++;
      if (g & 1) {
        z0 += 0.011;
        k++;
        ansx[k] = z0 * z0 / 2.0;
        ansy[k] = y0;
        ansz[k] = z0;
      } else {
        k++;
        ansx[k] = z0 * z0 / 2.0;
        ansy[k] = y0;
        ansz[k] = -z0;
      }
    }
    cout << k << "\n";
    for (ll i = 1; i <= k; i++) {
      cout << ansx[i] << " " << ansy[i] << " " << ansz[i] << "\n";
    }
    // bool ok = true;
    // int tot = 0;
    // for (int i = 1; i <= k; i++) {
    //   int sum = 0;
    //   for (int j = 1; j < i; j++) {
    //     db val = dis(ansx[i], ansy[i], ansz[i], ansx[j], ansy[j], ansz[j]);
    //     if (val <= 0.01) ok = false;
    //     if (val < 1.01 && val > 0.99) sum++;
    //   }
    //   for (int j = i + 1; j <= k; j++) {
    //     db val = dis(ansx[i], ansy[i], ansz[i], ansx[j], ansy[j], ansz[j]);
    //     if (val <= 0.01) ok = false;
    //     if (val < 1.01 && val > 0.99) sum++;
    //   }
    //   if (sum == n) tot++;
    //   else cout<<i<<"\n";
    // }
    // if (tot != k) ok = false;
    // if (!ok) {
    //   cout << "NO" << "\n";
    // } else {
    //   cout << "Yes" << "\n";
    // }
  }

  return 0;
}