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
    count,sm = 0,0
    isNeg = False
    for i in a:
        sm += abs(i)
        if isNeg and i>0:
            count += 1
            isNeg = False
        elif not isNeg and i<0: isNeg = True
    if isNeg: count += 1
    return sm,count


def getIns():
    for _ in range(int(input())):
        s,c = solve()
        print(s,c)

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()