def solve():
    n = int(input())
    b = list(map(int,input().split(" ")))
    ans = [b[0]]
    for i in range(1,n):
        if b[i]>=b[i-1]: ans.append(b[i])
        else:
            ans.append(b[i])
            ans.append(b[i])
    return ans

def getIns():
    for _ in range(int(input())):
        ans = solve()
        print(len(ans))
        for e in ans: print(e,end=" ")
        print()

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()