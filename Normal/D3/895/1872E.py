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
    s = input()
    x1 = 0
    prefixX = [0]
    for i,ai in enumerate(a):
        prefixX.append(prefixX[-1]^ai)
        if s[i]=='1': x1 ^= ai
    for _ in range(int(input())):
        q = list(map(int,input().split(" ")))
        if q[0]==1:
            l,r = q[1],q[2]
            x1 ^= prefixX[r]^prefixX[l-1]
        else:
            if q[1]: print(x1,end=" ")
            else: print(prefixX[-1]^x1,end=" ")
    print()


def getIns():
    for _ in range(int(input())):
        solve()

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()