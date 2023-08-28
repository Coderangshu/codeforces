from math import log2


def solve():
    n = int(input())
    ans = [n]
    nearestPow2 = int(log2(n))
    d = n-2**nearestPow2
    ithBit = 0
    while d:
        num = (1<<ithBit)
        ithBit += 1
        if d&num:
            n -= num
            ans.append(n)
            d -= num
    while n>1:
        ans.append(n//2)
        n //= 2
    return ans

def getIns():
    for _ in range(int(input())):
        ans = solve()
        print(len(ans))
        for i in ans: print(i,end=" ")
        print()

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()