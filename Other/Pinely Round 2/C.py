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
    n,k = list(map(int,input().split(" ")))
    a = list(map(int,input().split(" ")))
    mexCal = [0]*(n+1)
    for i in a:
        if i<=n: mexCal[i] = 1
    mex = 0
    while mex<=n and mexCal[mex]: mex += 1
    a.append(mex)
    # print(a)

    k %= (n+1)
    a = a[n+1-k:]+a[:n+1-k]
    return a[:-1]



def getIns():
    for _ in range(int(input())):
        ans = solve()
        for i in ans: print(i,end=" ")
        print()

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()