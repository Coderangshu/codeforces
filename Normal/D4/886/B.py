def solve():
    n = int(input())
    q,ans = float("-inf"),0
    for i in range(1,n+1):
        a,b = list(map(int,input().split(" ")))
        if a<=10:
            if b>q:
                q = b
                ans = i
    return(ans)

def getIns():
    for _ in range(int(input())):
        print(solve())

# getIns()

from contextlib import redirect_stdout
with open('out.txt', 'w') as f:
    with redirect_stdout(f): getIns()