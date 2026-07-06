def solve() -> None:
  n = int(input())
  vec = [0 for _ in range(n)]
  for i in range(1, n + 1):
    print(vec[i])
  

def main() -> None:
  for _ in range(int(input)):
    print(f"TEST-CASE: {_}")
    solve()

if __name__ == "__main__":
  main()

