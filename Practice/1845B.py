# character to num
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
    xa,ya = list(map(int,input().split(" ")))
    xb,yb = list(map(int,input().split(" ")))
    xc,yc = list(map(int,input().split(" ")))
    ans = 1
    xab = (xb-xa)//(abs(xb-xa)) if xb!=xa else 0
    xyb = (yb-ya)//(abs(yb-ya)) if yb!=ya else 0
    xca = (xc-xa)//(abs(xc-xa)) if xc!=xa else 0
    yca = (yc-ya)//(abs(yc-ya)) if yc!=ya else 0

    if abs(xab+xca)==2: ans += min(abs(xb-xa),abs(xc-xa))
    if abs(xyb+yca)==2: ans += min(abs(yc-ya),abs(yb-ya))
    return ans

def getIns():
    for _ in range(int(input())):
        print(solve())

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()