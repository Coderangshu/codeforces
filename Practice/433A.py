import sys
sys.set_int_max_str_digits(0)

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
    f = [0,0]
    for i in a:
        if i==100:
            f[0] += 1
        else:
            f[1] += 1
    # print(f)
    if f[0]%2==0 and f[1]%2==0:
        return "YES"
    elif f[0]>=2 and f[0]%2==0 and f[1]%2!=0:
        return "YES"
    
    # t0 = 2*min(f[0]//2,f[1])
    # f[1] = f[1]-min(f[1],f[0]//2)
    # f[0] = f[0]-t0
    # print(f)
    # if f[0]%2==0 and f[1]%2==0:
        # return "YES"
    return "NO"
    

def getIns():
    # for _ in range(int(input())):
    ans = solve()

    print(ans)

        # for i in ans: print(i,end=" ")
        # print()

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()