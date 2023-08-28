def solve():
    n,k = list(map(int,input().split(" ")))
    ans = 0
    for i in range(n,-1,-1):
        f,s,ki,isPossible = i,n,k-2,True
        # print("S",f,s,ki,ans)
        while ki>0:
            ki -= 1
            bf = s-f
            s = f
            f = bf
            # print(f,s,ki)
            if f>s or f<0 or s<0:
                isPossible = False
                break

        if ki<=0 and isPossible: ans += 1
    return ans

def getIns():
    for _ in range(int(input())):
        print(solve())

# getIns()

from contextlib import redirect_stdout
with open('out.txt', 'w') as f:
    with redirect_stdout(f): getIns()