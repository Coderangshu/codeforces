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
    # a = list(map(int,input().split(" ")))
    n = int(input())
    ans = [0]*n
    ans[n//2] = 1
    if n>1:
        if ans[-1]==0: ans[-1] = 2
        else: ans[0] = 2
    if n>2: ans[0] = 3
    i,e = 0,4
    while i<n:
        if ans[i]==0:
            ans[i] = e
            e += 1
        i += 1
    return ans


def getIns():
    for _ in range(int(input())):
        ans = solve()
        for e in ans: print(e,end=" ")
        print()

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()