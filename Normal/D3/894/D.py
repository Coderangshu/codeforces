def solve():
    n = int(input())
    lo,hi = 1,n
    while lo<=hi:
        mid = (lo+hi)>>1
        c = mid*(mid-1)//2
        if c<=n: lo = mid+1
        else: hi = mid-1
    
    ans = hi
    totCombinationWDistinctNos = ans*(ans-1)//2
    extraSameTypeCombReq = n-totCombinationWDistinctNos
    # add same type again to ans as 2 of same type will form a new pair
    # whose count is denoted in the extraSameTypeCombReq variable
    ans += extraSameTypeCombReq
    return ans



def getIns():
    for _ in range(int(input())):
        print(solve())

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()