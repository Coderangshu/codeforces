def solve():
    carpet = []
    n,m = list(map(int,input().split(" ")))
    for _ in range(n): carpet.append(input())
    p = "vika"
    end = count = 0

    for i in range(m):
        for j in range(n):
            c = carpet[j][i]
            if c==p[end]:
                end += 1
                count += 1
                break
        if count==4: break
    return count==4

def getIns():
    for _ in range(int(input())):
        ans = solve()
        if ans: print("YES")
        else: print("NO")

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()