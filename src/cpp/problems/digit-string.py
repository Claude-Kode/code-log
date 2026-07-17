t = int(input())
for i in range(t):
    s = input()
    pref2 = 0
    suf = 0
    for x in s:
        if x == '1' or x == '3':
            suf += 1
    ans = pref2 + suf
    for x in s:
        if x == '2':
            pref2 += 1
        if x == '1' or x == '3':
            suf -= 1
        ans = max(ans, pref2 + suf)
    print(len(s) - ans) 