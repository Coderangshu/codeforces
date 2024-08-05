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
    b = list(map(int,input().split(" ")))
    f = [[0,0] for _ in range(2*n+1)]
    i = 0
    while i<n:
        count,num = 1,a[i]
        i += 1
        while i<n and a[i]==num:
            count += 1
            i += 1
        f[num][0] = max(f[num][0],count)

    i = 0
    while i<n:
        count,num = 1,b[i]
        i += 1
        while i<n and b[i]==num:
            count += 1
            i += 1
        f[num][1] = max(f[num][1],count)
    
    return max(a+b for a,b in f)
    

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