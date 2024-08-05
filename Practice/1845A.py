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
    n,k,x = list(map(int,input().split(" ")))
    if x!=1: return [True,[1]*n]
    elif k==1 or (k==2 and n%2==1): return [False]
    else: return [True,[2]*(n//2-1)+[3 if n%2==1 else 2]]

def getIns():
    for _ in range(int(input())):
        ans = solve()
        if not ans[0]: print("NO")
        else:
            print("YES")
            print(len(ans[1]))
            for i in ans[1]: print(i,end=" ")
            print()

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()