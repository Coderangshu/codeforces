def solve():
    n = int(input())
    ans = 0
    mfm = msm = float("inf")
    for _ in range(n):
        m = int(input())
        a = list(map(int,input().split(" ")))
        fm,sm = float("inf"),float("inf")
        for i in a:
            if i<=fm:
                sm = fm
                fm = i
            elif i<sm:
                sm = i
        ans += sm
        mfm = min(fm,mfm)
        msm = min(sm,msm)
    if n==1: return mfm
    ans += mfm
    ans -= msm
    return ans


def getIns():
    for _ in range(int(input())):
        print(solve())

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()