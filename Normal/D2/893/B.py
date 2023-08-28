from collections import defaultdict


def solve():
    n,m,d = list(map(int,input().split(" ")))
    s = list(map(int,input().split(" ")))
    s = [1-d]+s+[n+1]
    tot = 0
    for i in range(m+1): tot += 1+(s[i+1]-s[i]-1)//d
    tot -= 1
    ans,mp = tot,defaultdict(int)
    for i in range(1,m+1):
        removeIShop = tot-1-(s[i]-s[i-1]-1)//d-(s[i+1]-s[i]-1)//d+(s[i+1]-s[i-1]-1)//d
        mp[removeIShop] += 1
        ans = min(ans,removeIShop)
    return ans,mp[ans]

def getIns():
    for _ in range(int(input())):
        cc,c = solve()
        print(cc,c)

# getIns()

from contextlib import redirect_stdout
with open('out.txt', 'w') as f:
    with redirect_stdout(f): getIns()