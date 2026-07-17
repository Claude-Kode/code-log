  // auto conv = [&](map<int, int, greater<int>>& num_cnt) -> map<int, vector<int>, greater<int>> {
  //   map<int, vector<int>, greater<int>> cnt_num;
  //   for (auto& [num, cnt] : num_cnt) {
  //     cnt_num[cnt].push_back(num);
  //   }
  //   return cnt_num;
  // };

  // // auto mask = [&](map<int, vector<int>, greater<int>> cnt_num) -> int {
  // //   vector<int> vals;
  // //   dbug(cnt_num);
  // //   for (auto& [cnt, nums] : cnt_num) {
  // //     for (int i = 1; i <= cnt; i ++) {
  // //       for (auto& x : nums) {
  // //         vals.push_back(x);
  // //       }
  // //     }
  // //   }

  // //   dbug(vals);
  // //   // assert(vals.size() == 5);
  // //   int res = 0, base = 13;
  // //   while (!vals.empty()) {
  // //     int x = vals.back(); vals.pop_back();
  // //     res += x * base;
  // //     base *= 13;
  // //   }

  // //   return res;
  // // };

  // // pair(kind, val_mask)
  // auto best = [&](Card& t) -> pair<int, int> {
  //   auto& [num_cnt, cnt_num, sig_cnt, cnts] = t;
  //   int mx_val = num_cnt.begin() -> first, 
  //       mn_val = prev(num_cnt.end()) -> first, 
  //       mx_dif = mx_val - mn_val + 1;

  //   // dbug(mx_val, mn_val, mx_dif, num_cnt, cnt_num, sig_cnt, cnts);

  //   auto chk = [&](int val, int sig) -> bool {
  //     auto [lv, hv] = (val > 0 ? pair(val, val) : pair(1LL, 13LL));
  //     auto [lk, hk] = (sig > 0 ? pair(sig, sig) : pair(1LL,  4LL));

  //     // dbug(lv, hv, lk, hk);

  //     for (int v = hv; v >= lv; v --) {
  //       for (int k = hk; k >= lk; k --) {
  //         if (REM[v][k]) {
  //           REM[v][k] = 0;
  //           num_cnt[v] ++;
  //           return true;
  //         }
  //       }
  //     }

  //     return false;
  //   };

  //   // 9: 一种花色, 四种值, 连续
  //   if (sig_cnt.size() == 1 and (mx_val == 13 or mx_val == 12) and (mn_val == 9 or mn_val == 10) and num_cnt.size() == 4) {
  //     int need_v = 0, need_k = sig_cnt.begin() -> first;
  //     for (int i = 9; i <= 13; i ++) {
  //       if (num_cnt[i] == 0) { need_v = i; break; }
  //     }

  //     if (chk(need_v, need_k)) { 
  //       return pair(9LL, mask(conv(num_cnt))); 
  //     }
  //   } 

  //   // 8: 一种花色, 四种值, 连续
  //   if (sig_cnt.size() == 1 and num_cnt.size() == 4 and mx_dif <= 5) {
  //     int need_v = 0, need_k = sig_cnt.begin() -> first;
  //     if (mx_dif == 5) {
  //       for (int i = mn_val; i <= mx_val; i ++) {
  //         if (num_cnt[i] == 0) { need_v = i; break; }
  //       }

  //       if (chk(need_v, need_k)) {
  //         return pair(8LL, mask(conv(num_cnt))); 
  //       }
  //     } else {
  //       if (mn_val != 1  and chk(mn_val - 1, need_k)) {
  //         return pair(8LL, mask(conv(num_cnt)));
  //       }
  //       if (mx_val != 13 and chk(mx_val + 1, need_k)) {
  //         return pair(8LL, mask(conv(num_cnt)));
  //       }
  //     }
  //   }

  //   // 7: 4 + 1
  //   using VEC = vector<int>;
  //   if (cnts == VEC{4}) {
  //     if (chk(0LL, 0LL)) {
  //       return pair(7LL, mask(conv(num_cnt)));
  //     }
  //   }

  //   if (cnts == VEC{3, 1}) {
  //     int need_v = 0, need_k = 0;
  //     for (auto& [v, cnt] : num_cnt) if (cnt == 3) { need_v = v; break; }
  //     assert(need_v);
      
  //     if (chk(need_v, need_k)) {
  //       return pair(7LL, mask(conv(num_cnt)));
  //     }
  //   }
    

  //   // 6: 3 + 2
  //   if (cnts == VEC{3, 1}) {
  //     int need_v = 0, need_k = 0;
  //     for (auto& [v, cnt] : num_cnt) if (cnt == 1) { need_v = v; break; }
  //     // assert(need_v);
      
  //     if (chk(need_v, need_k)) {
  //       return pair(6LL, mask(conv(num_cnt)));
  //     }
  //   }

  //   dbug(cnts);
  //   if (cnts == VEC{2, 2}) {
  //     // cout << "FIND\n";
  //     int need_v = 0, need_k = 0;
  //     dbug(num_cnt);
  //     for (auto& [v, cnt] : num_cnt) if (cnt == 2) { 
  //       need_v = v; 
  //       // dbug("22 -- 32", need_v);
  //       if (chk(need_v, need_k)) {
  //         return pair(6LL, mask(conv(num_cnt)));
  //       }
  //     }
  //   }

  //   // 5: 同花, 没有相同值
  //   if (sig_cnt.size() == 1 and num_cnt.size() == 4) {
  //     int need_v = 0, need_k = sig_cnt.begin() -> first;;
  //     for (int i = 13; i > 0; i --) {
  //       if (num_cnt[i] == 0) {
  //         need_v = i;
  //         if (chk(need_v, need_k)) {
  //           return pair(5LL, mask(conv(num_cnt)));
  //         }
  //       }
  //     }
  //   }

  //   // 4: 递增排列, 
  //   if (num_cnt.size() == 4 and mx_dif <= 5) {
  //     int need_v = 0, need_k = 0;
  //     if (mx_dif == 5) {
  //       for (int i = mn_val; i <= mx_val; i ++) {
  //         if (num_cnt[i] == 0) { need_v = i; break; }
  //       }

  //       if (chk(need_v, need_k)) {
  //         return pair(4LL, mask(conv(num_cnt))); 
  //       }
  //     } else {
  //       if (mn_val != 1  and chk(mn_val - 1, need_k)) {
  //         return pair(4LL, mask(conv(num_cnt)));
  //       }
  //       if (mx_val != 13 and chk(mx_val + 1, need_k)) {
  //         return pair(4LL, mask(conv(num_cnt)));
  //       }
  //     }
  //   }

  //   // 3: 3 + 1 + 1 
  //   if (cnts == VEC{3, 1}) {
  //     int need_v = 0, need_k = 0;
  //     for (int i = 13; i > 0; i --) {
  //       if (num_cnt[i] == 0) {
  //         need_v = i;
  //         if (chk(need_v, need_k)) {
  //           return pair(3LL, mask(conv(num_cnt)));
  //         }
  //       }
  //     }
  //   }

  //   if (cnts == VEC{2, 1, 1}) {
  //     int need_v = 0, need_k = 0;
  //     for (int i = 13; i > 0; i --) {
  //       if (num_cnt[i] == 2) {
  //         need_v = i;
  //         if (chk(need_v, need_k)) {
  //           return pair(3LL, mask(conv(num_cnt)));
  //         }
  //       }
  //     }
  //   }

  //   // 2: 2 + 2 + 1
  //   if (cnts == VEC{2, 2}) {
  //     // cout << "11111111111111111111111111111111111111111111111111111111111111111111111111111\n";
  //     int need_v = 0, need_k = 0;
  //     for (int i = 13; i > 0; i --) {
  //       if (num_cnt[i] == 0) {
  //         need_v = i;
  //         if (chk(need_v, need_k)) {
  //           return pair(2LL, mask(conv(num_cnt)));
  //         }
  //       }
  //     }
  //   }

  //   if (cnts == VEC{2, 1, 1}) {
  //     int need_v = 0, need_k = 0;
  //     for (int i = 13; i > 0; i --) {
  //       if (num_cnt[i] == 1) {
  //         need_v = i;
  //         if (chk(need_v, need_k)) {
  //           return pair(3LL, mask(conv(num_cnt)));
  //         }
  //       }
  //     }
  //   }

  //   // 1: 2 + 1 + 1 + 1
  //   if (cnts == VEC{2, 1, 1}) {
  //     int need_v = 0, need_k = 0;
  //     for (int i = 13; i > 0; i --) {
  //       if (num_cnt[i] == 0) {
  //         need_v = i;
  //         if (chk(need_v, need_k)) {
  //           return pair(1LL, mask(conv(num_cnt)));
  //         }
  //       }
  //     }
  //   }

  //   if (cnts == VEC{1, 1, 1, 1}) {
  //     int need_v = 0, need_k = 0;
  //     for (int i = 13; i > 0; i --) {
  //       if (num_cnt[i] == 1) {
  //         need_v = i;
  //         if (chk(need_v, need_k)) {
  //           return pair(1LL, mask(conv(num_cnt)));
  //         }
  //       }
  //     }
  //   }

  //   // 0: 1 + 1 + 1 + 1 + 1
  //   if (cnts == VEC{1, 1, 1, 1}) {
  //     int need_v = 0, need_k = 0;
  //     for (int i = 13; i > 0; i --) {
  //       if (num_cnt[i] == 0) {
  //         need_v = i;
  //         if (chk(need_v, need_k)) {
  //           return pair(0LL, mask(conv(num_cnt)));
  //         }
  //       }
  //     }
  //   }

  //   return {-1, -1};
  // };

  //   auto conv = [&](map<int, int, greater<int>>& num_cnt) -> map<int, vector<int>, greater<int>> {
  //   map<int, vector<int>, greater<int>> cnt_num;
  //   for (auto& [num, cnt] : num_cnt) {
  //     cnt_num[cnt].push_back(num);
  //   }
  //   return cnt_num;
  // };

  // auto mask = [&](map<int, vector<int>, greater<int>> cnt_num) -> int {
  //   vector<int> vals;
  //   dbug(cnt_num);
  //   for (auto& [cnt, nums] : cnt_num) {
  //     for (int i = 1; i <= cnt; i ++) {
  //       for (auto& x : nums) {
  //         vals.push_back(x);
  //       }
  //     }
  //   }

  //   dbug(vals);
  //   // assert(vals.size() == 5);
  //   int res = 0, base = 13;
  //   while (!vals.empty()) {
  //     int x = vals.back(); vals.pop_back();
  //     res += x * base;
  //     base *= 13;
  //   }

  //   return res;
  // };

  // // pair(kind, val_mask)
  // auto best = [&](Card& t) -> pair<int, int> {
  //   auto& [num_cnt, cnt_num, sig_cnt, cnts] = t;
  //   int mx_val = num_cnt.begin() -> first, 
  //       mn_val = prev(num_cnt.end()) -> first, 
  //       mx_dif = mx_val - mn_val + 1;

  //   // dbug(mx_val, mn_val, mx_dif, num_cnt, cnt_num, sig_cnt, cnts);

  //   // 9: 一种花色, 四种值, 连续
  //   if (sig_cnt.size() == 1 and mx_val == 13 and mn_val == 9 and num_cnt.size() == 5) {
  //     return pair(9LL, mask(cnt_num));
  //   } 

  //   // 8: 一种花色, 四种值, 连续
  //   if (sig_cnt.size() == 1 and num_cnt.size() == 5 and mx_dif == 5) {
  //     return pair(8LL, mask(cnt_num));
  //   }

  //   // 7: 4 + 1
  //   using VEC = vector<int>;
  //   if (cnts == VEC{4, 1}) {
  //     return pair(7LL, mask(conv(num_cnt)));
  //   }

  //   // 6: 3 + 2
  //   if (cnts == VEC{3, 2}) {
  //     return pair(6LL, mask(conv(num_cnt)));
  //   }


  //   // 5: 同花, 没有相同值
  //   if (sig_cnt.size() == 1 and num_cnt.size() == 5) {
  //     return pair(5LL, mask(conv(num_cnt)));
  //   }

  //   // 4: 递增排列, 
  //   if (num_cnt.size() == 5 and mx_dif == 5) {
  //     return pair(4LL, mask(conv(num_cnt)));
  //   }

  //   // 3: 3 + 1 + 1 
  //   if (cnts == VEC{3, 1, 1}) {
  //     return pair(3LL, mask(conv(num_cnt)));
  //   }

  //   // 2: 2 + 2 + 1
  //   if (cnts == VEC{2, 2, 1}) {
  //     return pair(2LL, mask(conv(num_cnt)));
  //   }

  //   // 1: 2 + 1 + 1 + 1
  //   if (cnts == VEC{2, 1, 1, 1}) {
  //     return pair(1LL, mask(conv(num_cnt)));
  //   }

  //   // 0: 1 + 1 + 1 + 1 + 1
  //   if (cnts == VEC{1, 1, 1, 1, 1}) {
  //     return pair(0LL, mask(conv(num_cnt)));
  //   }

  //   return {-1, -1};
  // };