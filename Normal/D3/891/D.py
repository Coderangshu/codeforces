def solve():
    n = int(input())
    a = list(map(int,input().split(" ")))
    b = list(map(int,input().split(" ")))
    c = [(ai-bi,i) for i,(ai,bi) in enumerate(zip(a,b))]
    ac,ans,maxDiff = 0,[],float("-inf")
    for diff,i in c:
        if diff>maxDiff:
            maxDiff = diff
            ac = 1
            ans = [i+1]
        elif diff==maxDiff:
            ac += 1
            ans.append(i+1)
    return (ac,ans)

def getIns():
    for _ in range(int(input())):
        ac,ans = solve()
        print(ac)
        for e in ans: print(e,end=" ")
        print()

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()