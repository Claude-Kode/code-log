# @Author : GoryK
import sys
from collections import defaultdict, deque, Counter
from itertools import accumulate, permutations, combinations
from math import gcd, lcm, sqrt, ceil, floor
import bisect

input = sys.stdin.readline
sys.setrecursionlimit(1 << 25)
# print = lambda x: sys.stdout.write(str(x) + '\n')

def dbug(*vars):
  for v in vars:
    print(f"{v=}")

# next 数组的含义
# next[j] 表示：在模式串 P 中，子串 P[0 .. j - 1]
# （即 P 的前 j 个字符）的 
# 最长相等真前缀与真后缀的长度。
# next[j] 的值，就是当 P[j] 与主串失配时，模式串指针 j 应该回跳到的位置。

def build_next(p: str) -> list:
  m = len(p)
  nxt = [0] * m
  j = 0
  for i in range(1, m):
    while j and p[i] != p[j]:
      j = nxt[j - 1]
    if p[i] == p[j]:
      j += 1
    nxt[i] = j
  return nxt

def kmp(s: str, p: str) -> list:
  n, m = len(s), len(p)
  nxt = build_next(p)
  res = []
  j = 0
  for i in range(n):
    while j and s[i] != p[j]:
      j = nxt[j - 1]
    if s[i] == p[j]:
      j += 1
    if j == m:
      res.append(i - m + 1)
      j = nxt[j - 1]
  return res

def solve():
  s = input().strip()
  p = input().strip()
  ans = kmp(s, p)
  for x in ans:
    print(x + 1)
  
  nxt = build_next(p)
  print(' '.join(map(str, nxt)))
  # for x in nxt:
    # print(' '.join(map(str, nxt[1:])))
    # print(f"{x} ")

def main():
  
  tt = 1
  # tt = int(input())
  
  for case_idx in range(1, tt + 1):
    # dbug(f"\nTEST CASE : {case_idx}")
    solve()

if __name__ == "__main__":
  main()