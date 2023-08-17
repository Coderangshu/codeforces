def solve():
    n = int(input())
    a = list(map(int,input().split(" ")))
    if n==1: return "YES"
    sa = sorted(a)
    for e,se in zip(a,sa):
        if (e%2==0 and se%2!=0) or (e%2!=0 and se%2==0):
            return "NO"
    return "YES"

def getIns():
    for _ in range(int(input())):
        print(solve())

# getIns()

from contextlib import redirect_stdout
with open('out.txt', 'w') as f:
    with redirect_stdout(f): getIns()