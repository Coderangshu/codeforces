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
    n,a,q = list(map(int,input().split(" ")))
    noti = input()
    if n<=a: return "YES"
    left = n-a
    for c in noti:
        if c=='+':
            left -= 1
            a += 1
        else: a -= 1
        if a>=n: return "YES"
    
    return "MAYBE" if left<=0 else "NO"



def getIns():
    for _ in range(int(input())):
        print(solve())

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()