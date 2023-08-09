def solve():
    n = int(input())
    a = list(map(int,input().split(" ")))
    b, p, l = True, float("inf"), float("-inf")
    for e in reversed(a):
        # print(e)
        if e>p: b = False
        if not b: l = max(e,l)
        p = e
    return l if not b else 0

def getIns():
    t = int(input())
    while t > 0:
        t -= 1
        print(solve())

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()