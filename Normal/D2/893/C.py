def solve():
    n = int(input())
    taken = [False]*(n+1)
    ans = []
    for i in range(1,n+1):
        if not taken[i]:
            ans.append(i)
            taken[i] = True
            e = 2*i
            while e<=n:
                if not taken[e]:
                    ans.append(e)
                    taken[e] = True
                    e *= 2
    return ans
    
def getIns():
    for _ in range(int(input())):
        ans = solve()
        for i in ans: print(i,end=" ")
        print()

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()