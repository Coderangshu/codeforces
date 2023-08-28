def solve():
    n,k = list(map(int,input().split(" ")))
    a = list(map(int,input().split(" ")))

    def isPossible(e: int) -> bool:
        if e<=max(a): return True
        for i in range(n-1):
            remTask,target,aTemp,j = k,e,[ele for ele in a],i
            while True:
                if j==n or remTask<0: break
                if aTemp[j]>=target: return True
                remTask -= (target-aTemp[j])
                aTemp[j] = target
                target -= 1
                j += 1
        return False
    
    lo,hi = min(a),max(a)+k
    while lo<=hi:
        mid = (lo+hi)>>1
        if isPossible(mid): lo = mid+1
        else: hi = mid-1
    return hi


def getIns():
    t = int(input())
    while t > 0:
        t -= 1
        print(solve())

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()