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
    a = sum(list(map(int,input().split(" "))))
    b = sum(list(map(int,input().split(" "))))
    if a==b: return "Draw"
    elif a<b: return "Tenzing"
    else: return "Tsondu"


def getIns():
    for _ in range(int(input())):
        print(solve())

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()