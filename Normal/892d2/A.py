def solve():
    n = int(input())
    a = list(map(int,input().split(" ")))
    mx = max(a)
    cnt = 0
    for i in a:
        if i==mx: cnt += 1
    b = [i for i in a if i!=mx]
    c = [mx]*cnt
    return b,c

def getIns():
    for _ in range(int(input())):
        b,c = solve()
        if len(b)==0 or len(c)==0: print(-1)
        else:
            print(len(b),len(c))
            for bi in b: print(bi,end=" ")
            print()
            for ci in c: print(ci,end=" ")
            print()

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()