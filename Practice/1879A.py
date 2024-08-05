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
    n = int(input())
    earr = []
    sf,ef,mxsltsf = -1,-1,float("-inf")
    possible = True
    for _ in range(n):
        s,e = list(map(int,input().split(" ")))
        if sf==-1:
            sf = s
            ef = e
            continue
        if s<sf: mxsltsf = max(mxsltsf,s)
        elif s==sf:
            if e>=ef: possible = False
        else:
            if e>=ef: possible = False
    if not possible: return -1
    ans = mxsltsf+1 if mxsltsf!=float("-inf") else sf
    return ans
    

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