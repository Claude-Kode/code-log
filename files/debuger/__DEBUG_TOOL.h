#ifndef DEBUG_HPP
#define DEBUG_HPP

#include <array>
#include <cstddef>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// ============================================================
// Codeforces / 本地调试工具 — 详细说明见:
//   notes/DEBUG-TOOL-KNOWLEDGE.md   ← 本 hpp 每个知识点的口语讲解（推荐先读）
//   notes/CPP-LEVEL-AND-ROADMAP.md  ← 整体 C++ 水平与学习路线
//
// 【快速用法】
//   1. 编译加 -DLOCAL  (source/.vscode/tasks.json 已配置)
//   2. #ifdef LOCAL
//      #include "__DEBUG_TOOL.h"
//      #endif
//   3. debug(a, b, mp);           // 可同时打印多个变量，输出到 cerr
//
// 【自定义结构体 — 必须注册成员名，C++ 无法自动反射】
//   struct Node { int x, y; };
//   REGISTER_REFLECT(Node, x, y)  // 写在 struct 定义之后
//   // 输出: Node { x: 1, y: 2 }
//
// 【支持类型】
//   基础类型 | pair | vector/array | map/unordered_map
//   | set/unordered_set/multiset | tuple | 任意嵌套
//   | REGISTER_REFLECT 注册过的 struct
//
// 【文件结构 — 由易到难读源码】
//   DBG_FOREACH / debug 宏     → 把 debug(a,b) 展开成多行打印
//   print_val                  → 核心：按类型递归打印 (先读这个)
//   REGISTER_REFLECT           → 结构体成员名: 值
//   is_map_like / is_set_like  → 编译期判断类型 (进阶)
// ============================================================

#define DBG_N_IMPL(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, \
                   _15, N, ...)                                                \
  N
#define DBG_N(...) \
  DBG_N_IMPL(__VA_ARGS__, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)

#define DBG_CAT_I(a, b) a##b
#define DBG_CAT(a, b) DBG_CAT_I(a, b)

#define DBG_MAP_0(m)
#define DBG_MAP_1(m, x) m(x)
#define DBG_MAP_2(m, x, ...) m(x) DBG_MAP_1(m, __VA_ARGS__)
#define DBG_MAP_3(m, x, ...) m(x) DBG_MAP_2(m, __VA_ARGS__)
#define DBG_MAP_4(m, x, ...) m(x) DBG_MAP_3(m, __VA_ARGS__)
#define DBG_MAP_5(m, x, ...) m(x) DBG_MAP_4(m, __VA_ARGS__)
#define DBG_MAP_6(m, x, ...) m(x) DBG_MAP_5(m, __VA_ARGS__)
#define DBG_MAP_7(m, x, ...) m(x) DBG_MAP_6(m, __VA_ARGS__)
#define DBG_MAP_8(m, x, ...) m(x) DBG_MAP_7(m, __VA_ARGS__)
#define DBG_MAP_9(m, x, ...) m(x) DBG_MAP_8(m, __VA_ARGS__)
#define DBG_MAP_10(m, x, ...) m(x) DBG_MAP_9(m, __VA_ARGS__)
#define DBG_MAP_11(m, x, ...) m(x) DBG_MAP_10(m, __VA_ARGS__)
#define DBG_MAP_12(m, x, ...) m(x) DBG_MAP_11(m, __VA_ARGS__)
#define DBG_MAP_13(m, x, ...) m(x) DBG_MAP_12(m, __VA_ARGS__)
#define DBG_MAP_14(m, x, ...) m(x) DBG_MAP_13(m, __VA_ARGS__)
#define DBG_MAP_15(m, x, ...) m(x) DBG_MAP_14(m, __VA_ARGS__)

#define DBG_FOREACH(m, ...) \
  DBG_CAT(DBG_MAP_, DBG_N(__VA_ARGS__))(m, __VA_ARGS__)

namespace refl {
template <typename T>
struct refl_traits {
  static constexpr bool available = false;
  static constexpr const char* name = "";
};
}  // namespace refl

#define _REFL_BODY_1(obj, f, m1) f(#m1, (obj).m1);
#define _REFL_BODY_2(obj, f, m1, m2) \
  f(#m1, (obj).m1);                  \
  f(#m2, (obj).m2);
#define _REFL_BODY_3(obj, f, m1, m2, m3) \
  f(#m1, (obj).m1);                      \
  f(#m2, (obj).m2);                      \
  f(#m3, (obj).m3);
#define _REFL_BODY_4(obj, f, m1, m2, m3, m4) \
  f(#m1, (obj).m1);                          \
  f(#m2, (obj).m2);                          \
  f(#m3, (obj).m3);                          \
  f(#m4, (obj).m4);
#define _REFL_BODY_5(obj, f, m1, m2, m3, m4, m5) \
  f(#m1, (obj).m1);                              \
  f(#m2, (obj).m2);                              \
  f(#m3, (obj).m3);                              \
  f(#m4, (obj).m4);                              \
  f(#m5, (obj).m5);
#define _REFL_BODY_6(obj, f, m1, m2, m3, m4, m5, m6) \
  f(#m1, (obj).m1);                                  \
  f(#m2, (obj).m2);                                  \
  f(#m3, (obj).m3);                                  \
  f(#m4, (obj).m4);                                  \
  f(#m5, (obj).m5);                                  \
  f(#m6, (obj).m6);
#define _REFL_BODY_7(obj, f, m1, m2, m3, m4, m5, m6, m7) \
  f(#m1, (obj).m1);                                      \
  f(#m2, (obj).m2);                                      \
  f(#m3, (obj).m3);                                      \
  f(#m4, (obj).m4);                                      \
  f(#m5, (obj).m5);                                      \
  f(#m6, (obj).m6);                                      \
  f(#m7, (obj).m7);
#define _REFL_BODY_8(obj, f, m1, m2, m3, m4, m5, m6, m7, m8) \
  f(#m1, (obj).m1);                                          \
  f(#m2, (obj).m2);                                          \
  f(#m3, (obj).m3);                                          \
  f(#m4, (obj).m4);                                          \
  f(#m5, (obj).m5);                                          \
  f(#m6, (obj).m6);                                          \
  f(#m7, (obj).m7);                                          \
  f(#m8, (obj).m8);
#define _REFL_BODY_9(obj, f, m1, m2, m3, m4, m5, m6, m7, m8, m9) \
  f(#m1, (obj).m1);                                              \
  f(#m2, (obj).m2);                                              \
  f(#m3, (obj).m3);                                              \
  f(#m4, (obj).m4);                                              \
  f(#m5, (obj).m5);                                              \
  f(#m6, (obj).m6);                                              \
  f(#m7, (obj).m7);                                              \
  f(#m8, (obj).m8);                                              \
  f(#m9, (obj).m9);
#define _REFL_BODY_10(obj, f, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10) \
  f(#m1, (obj).m1);                                                      \
  f(#m2, (obj).m2);                                                      \
  f(#m3, (obj).m3);                                                      \
  f(#m4, (obj).m4);                                                      \
  f(#m5, (obj).m5);                                                      \
  f(#m6, (obj).m6);                                                      \
  f(#m7, (obj).m7);                                                      \
  f(#m8, (obj).m8);                                                      \
  f(#m9, (obj).m9);                                                      \
  f(#m10, (obj).m10);

#define REGISTER_REFLECT(Type, ...)                        \
  namespace refl {                                         \
  template <>                                              \
  struct refl_traits<Type> {                               \
    static constexpr bool available = true;                \
    static constexpr const char* name = #Type;             \
    template <typename F>                                  \
    static void for_each(const Type& obj, F&& f) {         \
      DBG_CAT(_REFL_BODY_, DBG_N(__VA_ARGS__))(obj, f, __VA_ARGS__); \
    }                                                      \
  };                                                       \
  }

namespace debug_detail {

  template <typename T>
  std::ostream& print_val(std::ostream& os, const T& val);

  template <typename T>
  struct is_pair : std::false_type {};
  template <typename A, typename B>
  struct is_pair<std::pair<A, B>> : std::true_type {};

  template <typename T, typename = void>
  struct is_map_like : std::false_type {};
  template <typename T>
  struct is_map_like<T, std::void_t<typename T::mapped_type>> : std::true_type {};

  template <typename T, typename = void>
  struct is_set_like : std::false_type {};
  template <typename T>
  struct is_set_like<T, std::void_t<typename T::key_type>>
      : std::bool_constant<!is_map_like<T>::value> {};

  template <typename T, typename = void>
  struct is_tuple_like : std::false_type {};
  template <typename T>
  struct is_tuple_like<T, std::void_t<decltype(std::tuple_size<T>::value)>>
      : std::bool_constant<!is_pair<T>::value> {};

  template <typename T, typename = void>
  struct is_iterable : std::false_type {};
  template <typename T>
  struct is_iterable<
      T, std::void_t<decltype(std::begin(std::declval<const T&>()) !=
                              std::end(std::declval<const T&>()))>>
      : std::true_type {};

  template <std::size_t I, typename Tuple>
  void print_tuple_elem(std::ostream& os, const Tuple& tup) {
    if constexpr (I > 0) os << ", ";
    print_val(os, std::get<I>(tup));
  }

  template <typename Tuple, std::size_t... Is>
  void print_tuple(std::ostream& os, const Tuple& tup,
                  std::index_sequence<Is...>) {
    (print_tuple_elem<Is>(os, tup), ...);
  }

  template <typename T, std::size_t N>
  std::ostream& print_val(std::ostream& os, const T (&arr)[N]) {
    os << '[';
    for (std::size_t i = 0; i < N; ++i) {
      if (i) os << ", ";
      print_val(os, arr[i]);
    }
    return os << ']';
  }

  template <typename T>
  std::ostream& print_val(std::ostream& os, const T& val) {
    using D = std::decay_t<T>;

    if constexpr (std::is_same_v<D, bool>) {
      os << (val ? "true" : "false");
    } else if constexpr (std::is_same_v<D, char>) {
      os << '\'' << val << '\'';
    } else if constexpr (std::is_same_v<D, signed char> ||
                        std::is_same_v<D, unsigned char>) {
      os << static_cast<int>(val);
    } else if constexpr (std::is_same_v<D, std::string> ||
                        std::is_same_v<D, std::string_view>) {
      os << '"' << val << '"';
    } else if constexpr (std::is_same_v<D, const char*> ||
                        std::is_same_v<D, char*>) {
      os << '"' << val << '"';
    } else if constexpr (std::is_same_v<D, std::nullptr_t>) {
      os << "nullptr";
    } else if constexpr (std::is_pointer_v<D>) {
      os << static_cast<const void*>(val);
    } else if constexpr (std::is_arithmetic_v<D>) {
      os << val;
    } else if constexpr (is_pair<D>::value) {
      os << '(';
      print_val(os, val.first);
      os << ", ";
      print_val(os, val.second);
      os << ')';
    } else if constexpr (is_tuple_like<D>::value) {
      os << '(';
      print_tuple(os, val, std::make_index_sequence<std::tuple_size_v<D>>{});
      os << ')';
    } else if constexpr (is_map_like<D>::value) {
      os << '{';
      bool first = true;
      for (const auto& [k, v] : val) {
        if (first)
          first = false;
        else
          os << ", ";
        print_val(os, k);
        os << ": ";
        print_val(os, v);
      }
      os << '}';
    } else if constexpr (is_set_like<D>::value) {
      os << '{';
      bool first = true;
      for (const auto& e : val) {
        if (first)
          first = false;
        else
          os << ", ";
        print_val(os, e);
      }
      os << '}';
    } else if constexpr (is_iterable<D>::value) {
      os << '[';
      bool first = true;
      for (const auto& e : val) {
        if (first)
          first = false;
        else
          os << ", ";
        print_val(os, e);
      }
      os << ']';
    } else if constexpr (refl::refl_traits<D>::available) {
      os << refl::refl_traits<D>::name << " { ";
      bool first = true;
      refl::refl_traits<D>::for_each(val, [&](const char* name, const auto& member) {
        if (first)
          first = false;
        else
          os << ", ";
        os << name << ": ";
        print_val(os, member);
      });
      os << " }";
    } else {
      os << val;
    }
    return os;
  }

}  

// namespace debug_detail
// cerr<< "  "
#define DBG_PRINT_ONE(var)                     \
  std::cout << #var << " = ";                  \
  debug_detail::print_val(std::cout, (var));   \
  std::cout << '\n';
// std::cerr << "[" << __FILE__ << ":" << __LINE__ << "]\n";
#define dbug(...)                                              \
  do {                                                         \
                                                               \
    DBG_FOREACH(DBG_PRINT_ONE, __VA_ARGS__)                    \
  } while (0)

#endif  // DEBUG_HPP
