vector<int> tagged(n << 2 | 1, 0);
vector<arr> seg(n << 2 | 1, arr{});
vector<int> tag(n << 2 | 1, -1);

auto apply = [&](int p, int c, int len) -> void {
  seg[p] = arr{};
  seg[p][c] = len;
  tag[p] = c;
  tagged[p] = 1;
};

auto push = [&](int p, int l, int r) -> void {
  if (!tagged[p]) return;
  int mid = (l + r) >> 1;
  apply(p * 2, tag[p], mid - l + 1);
  apply(p * 2 + 1, tag[p], r - mid);
  tag[p] = -1;
  tagged[p] = 0;
};

// 其他 pull, split（不再需要了）, build 照旧，但 build 里原来
// seg[p][s[l]-'a']++ 没问题

auto set = [&](auto&& sef, int p, int l, int r, int L, int R, int c) -> void {
  if (L <= l && r <= R) {
    apply(p, c, r - l + 1);
    return;
  }
  push(p, l, r);
  int mid = (l + r) >> 1;
  if (L <= mid) sef(sef, p * 2, l, mid, L, R, c);
  if (R > mid) sef(sef, p * 2 + 1, mid + 1, r, L, R, c);
  pull(p);
};

auto ask = [&](auto&& sef, int p, int l, int r, int L, int R) -> arr {
  if (L <= l && r <= R) return seg[p];
  push(p, l, r);
  int mid = (l + r) >> 1;
  arr res = {};
  if (L <= mid) res = res + sef(sef, p * 2, l, mid, L, R);
  if (mid < R) res = res + sef(sef, p * 2 + 1, mid + 1, r, L, R);
  return res;
};

// work 中的调用：
if (f) {
  for (int i = 0; i < 26; ++i) {
    if (a[i]) {
      set(set, 1, 1, n, l, l + a[i] - 1, i);
      l += a[i];
    }
  }
} else {
  for (int i = 25; i >= 0; --i) {
    if (a[i]) {
      set(set, 1, 1, n, l, l + a[i] - 1, i);
      l += a[i];
    }
  }
}