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
    l,r = list(map(int,input().split(" ")))
    if r<4: print(-1)
    elif r!=l: print(r//2,r//2) if r%2==0 else print((r-1)//2,(r-1)//2)
    elif r%2==0: print(r//2,r//2)
    elif l%2==0: print(l//2,l//2)
    else:
        i = ceil(sqrt(r))
        f = False
        while i>=3:
            if r%i==0:
                f = True
                q = r//i
                print(i,i*(q-1))
                break
            i -= 1
        if not f: print(-1)

def getIns():
    for _ in range(int(input())):
        solve()

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()