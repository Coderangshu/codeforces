def solve():
    n = int(input())
    a = list(map(int,input().split(" ")))
    req = 0
    for e in a:
        if e==1: req += 1
        else: req -= e-1
    return "NO" if n==1 or req>0 else "YES"

def getIns():
    t = int(input())
    while t > 0:
        t -= 1
        print(solve())


getIns()
# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()