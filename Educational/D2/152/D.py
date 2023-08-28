def solve():
    n = int(input())
    a = list(map(int,input().split(" ")))
    ans = 0
    for i in range(n):
        if i>0 and a[i-1]>0:
            a[i-1] -= 1
        elif i<n-1 and a[i+1]>0 and a[i]==0:
            a[i+1] -= 1
        else: ans += 1
        # print(i,ans)
    return ans

print(solve())

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f):
#         t = int(input())
#         while t:
#             t -= 1
#             print(solve())