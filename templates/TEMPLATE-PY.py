# @Author : GoryK
import sys
from collections import defaultdict, deque, Counter
from itertools import accumulate, permutations, combinations
from math import gcd, lcm, sqrt, ceil, floor
import bisect

input = sys.stdin.readline
sys.setrecursionlimit(1 << 25)

def dbug(*vars):
  for v in vars:
    print(f"{v=}")


def solve():
  n, m = map(int, input().split())
  ans = n + m
  print(ans)

def main():
  
  tt = 1
  # tt = int(input())
  
  for case_idx in range(1, tt + 1):
    # dbug(f"\nTEST CASE : {case_idx}")
    solve()

if __name__ == "__main__":
  main()