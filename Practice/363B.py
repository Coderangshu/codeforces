import sys
sys.set_int_max_str_digits(0)
from itertools import accumulate

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
    if n==k:
        return 1
    a = list(map(int,input().split(" ")))
    if k==1:
        return a.index(min(a))+1
    partial_sum = list(accumulate(a))
    # print(partial_sum)
    ans, mn = -1,sys.maxsize
    for i in range(n-k-1,-1,-1):
        if partial_sum[i+k]-partial_sum[i]<mn:
            # print(i)
            mn = partial_sum[i+k]-partial_sum[i]
            ans = i+2
    if partial_sum[k-1]<mn:
        mn = partial_sum[k-1]
        ans = 1
    return ans

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