def solve(): 
    w, h, a, b, x1, y1, x2, y2 = map(int, input().split())
    if x1 == x2 and abs(y1 - y2) % b == 0 : 
        print("YES")
        return 
    if y1 == y2 and abs(x1 - x2) % a == 0 : 
        print("YES")
        return 

    if abs(x1 - x2) % a == 0 or abs(y1 - y2) % b == 0 :
        print("YES")
    else :
        print("NO")

for _ in range(int(input())) : solve()