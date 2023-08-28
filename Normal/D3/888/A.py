def solve():
    n,m,k,H = list(map(int,input().split(" ")))
    h = list(map(int,input().split(" ")))
    ans = 0
    for i in h:
        d = abs(H-i)
        if d!=0 and d%k==0:
            if d//k<m: ans += 1
    return ans

def getIns():
    for _ in range(int(input())):
        print(solve())

# getIns()

from contextlib import redirect_stdout
with open('out.txt', 'w') as f:
    with redirect_stdout(f): getIns()