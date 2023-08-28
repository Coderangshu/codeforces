def solve():
    n,c = list(map(int,input().split(" ")))
    l = list(map(int,input().split(" ")))
    lo,hi = 0,10**10
    while lo<=hi:
        m = (lo+hi)>>1
        tot = 0
        for e in l: tot += (e+2*m)**2
        if tot<c: lo = m+1
        else: hi = m-1
    return(lo)

def getIns():
    for _ in range(int(input())):
        print(solve())

# getIns()

from contextlib import redirect_stdout
with open('out.txt', 'w') as f:
    with redirect_stdout(f): getIns()