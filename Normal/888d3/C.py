def solve():
    n,k = list(map(int,input().split(" ")))
    c = list(map(int,input().split(" ")))
    l,f,cnt1,cnt2 = -1,n,0,0
    for i in range(n):
        if c[i]==c[0]:
            cnt1 += 1
            if cnt1==k:
                l = i
                break
    for i in range(n-1,-1,-1):
        if c[i]==c[-1]:
            cnt2 += 1
            if cnt2==k:
                f = i
                break
    if l!=-1 and f!=n and (c[0]==c[-1] or l<=f): return "YES"
    return "NO"

def getIns():
    for _ in range(int(input())):
        print(solve())

# getIns()

from contextlib import redirect_stdout
with open('out.txt', 'w') as f:
    with redirect_stdout(f): getIns()