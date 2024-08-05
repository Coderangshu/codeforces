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
    ans = [[0]*(n+1) for i in range(3)]
    ans[1][1] = 2*n
    ans[2][n] = 2*n-1
    for i in range(1,n):
        if i%2==0:
            ans[1][i+1] = 2*n-2-(i-2)-1
            ans[2][i] = 2*n-2-(i-2)
        else:
            ans[1][i+1] = i
            ans[2][i] = i+1

    for i in range(1,3):
        for j in range(1,n+1):
            print(ans[i][j],end=" ")
        print()

def getIns():
    for _ in range(int(input())):
        ans = solve()

        # print(ans)

        # for i in ans: print(i,end=" ")
        # print()

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()