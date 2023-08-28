def solve():
    n = int(input())
    a = list(map(int,input().split(" ")))
    mnd = float("inf")
    for i in range(1,n):
        if a[i]-a[i-1]<0: return 0
        if a[i]-a[i-1]<mnd: mnd = a[i]-a[i-1]
    return mnd//2+1

def getIns():
    for _ in range(int(input())):
        print(solve())

# getIns()

from contextlib import redirect_stdout
with open('out.txt', 'w') as f:
    with redirect_stdout(f): getIns()