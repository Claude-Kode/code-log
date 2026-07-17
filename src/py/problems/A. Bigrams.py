t = int(input())
for i in range(t):
  k = int(input())
  a = list(map(int, input().split()))
  if max(a) > 2 or a.count(2) > 1:
    print("YES")
  else:
    print("NO") 
