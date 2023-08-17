def solve():
    n = int(input())
    l = list(map(int,input().split(" ")))
    cnt, freq = [0]*(n+1),[0]*(n+1)
    for e in l:
        if e<=n: cnt[e] += 1
    for i in range(n+1):
        if cnt[i]>0:
            for j in range(i,n+1,i):
                freq[j] += cnt[i]
    return(max(freq))

def getIns():
    for _ in range(int(input())):
        print(solve())

# getIns()

from contextlib import redirect_stdout
with open('out.txt', 'w') as f:
    with redirect_stdout(f): getIns()