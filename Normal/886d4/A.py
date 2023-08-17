def solve():
    l = list(map(int,input().split(" ")))
    l.sort()
    if l[-1]+l[-2]>=10:
        return("YES")
    else: return("NO")

def getIns():
    for _ in range(int(input())):
        print(solve())

# getIns()

from contextlib import redirect_stdout
with open('out.txt', 'w') as f:
    with redirect_stdout(f): getIns()