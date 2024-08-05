# character to num
from functools import cache


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
    n,m = list(map(int,input().split(" ")))
    @cache
    def recursive(n,m):
        if n==m: return True
        if n<m or n%3!=0: return False
        return recursive(n//3,m) or recursive(2*n//3,m)
    
    return "YES" if recursive(n,m) else "NO"

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