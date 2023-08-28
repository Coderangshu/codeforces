def solve():
    x,y,n = list(map(int,input().split(" ")))
    a,d = [y],1
    for _ in range(n-1):
        nxt = a[-1]-d
        if nxt<x: return [-1]
        d += 1
        a.append(nxt)
    a[-1] = x
    a.reverse()
    return a

def getIns():
    for _ in range(int(input())):
        a = solve()
        for e in a: print(e,end=" ")
        print()

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()