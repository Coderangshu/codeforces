def solve():
    n = int(input())
    a = sorted(list(map(int,input().split(" "))))
    j=0
    ans = []
    for i in range(n-1,0,-1):
        ans.append(a[j])
        j+=i
    ans.append(a[-1])
    return ans

def getIns():
    for _ in range(int(input())):
        a = solve()
        for i in a:
            print(i,end=" ")
        print()

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()