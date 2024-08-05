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
    n,m,k = list(map(int,input().split(" ")))
    x,y = list(map(int,input().split(" ")))
    oev = (x+y)%2
    flag = True
    for i in range(k):
        a,b = list(map(int,input().split(" ")))
        oef = (a+b)%2
        if oef==oev: flag = False
    return flag

def getIns():
    for _ in range(int(input())):
        ans = solve()
        if ans: print("YES")
        else: print("NO")

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()