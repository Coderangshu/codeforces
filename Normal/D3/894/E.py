from functools import cache


def solve():
    n,m,d = list(map(int,input().split(" ")))
    a = list(map(int,input().split(" ")))

    @cache
    def recursion(prevDay,m,i):
        if m==0 or i==n: return 0
        # take
        ans = a[i]-d*(i+1-prevDay)+recursion(i+1,m-1,i+1)
        # not take
        ans = max(ans,recursion(prevDay,m,i+1))
        return ans

    dp = [[[0,0]]*(m+1) for _ in range(n+1)]
    for mi in range(m,0,-1):
        for ii in range(n):
            # take
            ans = a[ii]-d*(ii+1-prevDay)+recursion(ii+1,mi-1,ii+1)
            # not take
            ans = max(ans,recursion(prevDay,mi,ii+1))
            return ans

    print(dp)

    return recursion(0,m,0)

def getIns():
    for _ in range(int(input())):
        print(solve())

# getIns()

from contextlib import redirect_stdout
with open('out.txt', 'w') as f:
    with redirect_stdout(f): getIns()