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
    if n%k!=0:
        print(1)
        print(n)
    else:
        q = n//k - 1
        fst = q*k + 1
        sec = n-fst
        print(2)
        print(fst,sec)
        

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