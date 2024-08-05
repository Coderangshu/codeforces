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
    n,m = list(map(int,input().split(" ")))
    def rec(n,m):
        if n>m: return rec(m,n)
        b = list(map(int,input().split(" ")))
        b.sort()
        mx1,mx2 = b[-1],b[-2]
        mn1,mn2 = b[0],b[1]
        a1 = (mx1-mn1)*n*(m-1)+(mx1-mn2)*(n-1)
        a2 = (mx1-mn1)*n*(m-1)+(mx2-mn1)*(n-1)
        return max(a1,a2) 
    return rec(n,m)


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