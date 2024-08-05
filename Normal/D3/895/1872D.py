# character to num
from math import gcd


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
    n,x,y = list(map(int,input().split(" ")))

    def dxy(x,y):
        divisibleByX = n//x
        divisibleByY = n//y
        LCM = int((x*y) / gcd(x,y))
        divisibleByLCM = n//LCM
        divisibleByXorY = (divisibleByX + divisibleByY - divisibleByLCM)
        divisibleByXnotY = (divisibleByXorY - divisibleByY)
        return divisibleByXnotY

    cx,cy = dxy(x,y),dxy(y,x)
    # print(cx,cy)
    r = n-cx
    ans = n*(n+1)//2 - r*(r+1)//2
    # print(ans)
    t = cy*(cy+1)//2
    # print(t)
    ans -= t
    return ans


def getIns():
    for _ in range(int(input())):
        print(solve())

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()