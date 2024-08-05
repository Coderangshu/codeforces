# character to num
from math import ceil, sqrt


def ctn(c: chr) -> int:
    return ord(c)-ord('a') if 'a'<=c<='z' else ord(c)-ord('A')

# num to character
def ntc(n: int, isSmall: bool) -> chr:
    n += ord('a') if isSmall else ord('A')
    return chr(n)

###################################################################################

# ctn -> character to num
# ntc -> num to character

def solve():
    # n = list(map(int,input().split(" ")))
    n = int(input())
    sn = sqrt(n)
    # print(sn)
    # print(ceil(sn))
    return int(sn-1) if sn**2==n else int(sn)

def getIns():
    for _ in range(int(input())):
        ans = solve()

        print(ans)

        # for i in ans: print(i,end=" ")
        # print()

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()