def solve():
    def sub_lists (p):
        l = []
        for i in range(len(p)):
            for j in range(i,len(p)):
                l.append(p[i:j+1])
        return l
    n = int(input())
    p = list(map(int,input().split(" ")))
    sl = sub_lists(p)
    # print(sl)
    ans = 0
    for l in sl:
        if len(l)>0:
            mn,mx = l.index(min(l)),l.index(max(l))
            if mx>mn: ans += 1
    return ans

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f):
        
        # t = int(input())
        # while t>0:
        #     t -= 1
print(solve())