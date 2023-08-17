def solve():
    n,k = list(map(int,input().split(" ")))
    l = list(map(int,input().split(" ")))
    l.sort()
    takeSegStart = 0
    takeSegLen = float("-inf")
    for i in range(1,n):
        if l[i]-l[i-1]>k:
            takeSegLen = max(takeSegLen,i-takeSegStart)
            takeSegStart = i
    takeSegLen = max(takeSegLen,n-takeSegStart)
    return(n-takeSegLen)

def getIns():
    for _ in range(int(input())):
        print(solve())

# getIns()

from contextlib import redirect_stdout
with open('out.txt', 'w') as f:
    with redirect_stdout(f): getIns()