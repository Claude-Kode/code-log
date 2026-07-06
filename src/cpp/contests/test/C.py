n = int(input())
a = list(map(int, input().split()))

prod = 1
for x in a:
  prod *= x

s = 1
cnt = 0
while s < prod:
  s *= 2024
  cnt += 1

print(cnt)