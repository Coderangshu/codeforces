from functools import cache


def solve():
    n = int(input())
    a = list(map(int,input().split(" ")))
    @cache
    def recursion(ind,bit):
        # print(bit)
        if bit==0: return 0
        if ind>=n: return 0
        ans,tans = 0,0
        for i in range(min(ind+1,n)):
            if bit&(1<<i) and a[i]!=0:
                bit &= ~(1<<i)
                #take
                tans = a[i]+recursion(ind,bit)
                # not take
                tans = max(tans,recursion(ind+a[i],bit))
                bit &= ~(1<<i)
            ans = max(tans,ans)
        return ans
    return recursion(0,(1<<n)-1)


# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f):
        
        # t = int(input())
        # while t>0:
        #     t -= 1
print(solve())