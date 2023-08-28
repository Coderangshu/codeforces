def solve():
    a = list(map(int,input()))
    a = [0]+a
    zeroStart = len(a)
    for i in range(len(a)-1,-1,-1):
        if a[i]>=5:
            a[i-1] += 1
            zeroStart = i
    a = a[:zeroStart]+[0]*(len(a)-zeroStart)
    return int("".join([str(i) for i in a]))

def getIns():
    t = int(input())
    while t > 0:
        t -= 1
        print(solve())

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()