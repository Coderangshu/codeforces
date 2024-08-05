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
    n,k,d,w = list(map(int,input().split(" ")))
    t = list(map(int,input().split(" ")))
    ans = vLeft = 0
    uptoTime = -1
    for i in t:
        if vLeft==0 or uptoTime<i :
            vLeft = k-1
            ans += 1
            uptoTime = i+d+w
        else: vLeft -= 1
    return ans
        
        

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