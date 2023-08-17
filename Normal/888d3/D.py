def solve():
    n = int(input())
    a = list(map(int,input().split(" ")))
    a = [0]+a
    ln, extra = [-1]*n, []
    for i in range(1,n):
        diff = a[i]-a[i-1]
        if diff<=n:
            if ln[diff-1]==-1: ln[diff-1] = diff
            else: extra.append(diff)
        else: extra.append(diff)
        if len(extra)>1: return "NO"
    li = [i+1 for i,j in enumerate(ln) if j==-1]
    if len(extra)==0 and len(li)==1: return "YES"
    sm = sum(li)
    return "YES" if sm==extra[0] else "NO"

def getIns():
    for _ in range(int(input())):
        print(solve())

# getIns()

from contextlib import redirect_stdout
with open('out.txt', 'w') as f:
    with redirect_stdout(f): getIns()