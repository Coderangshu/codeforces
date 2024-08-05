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
    a = list(map(int,input().split(" ")))
    if n%2==0:
        print(2)
        print(1,n)
        print(1,n)
    else:
        print(4)
        print(1,n-1)
        print(1,n-1)
        print(n-1,n)
        print(n-1,n)
    

def getIns():
    for _ in range(int(input())):
        solve()

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()