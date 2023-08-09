# def funA() -> int:
    # n = int(input())
    # a = list(map(int,input().split(" ")))
    # mnd = float("inf")
    # for i in range(1,n):
    #     if a[i]-a[i-1]<0: return 0
    #     if a[i]-a[i-1]<mnd: mnd = a[i]-a[i-1]
    # return mnd//2+1

# def funB():
#     n,k = list(map(int,input().split(" ")))
#     ans = 0
#     for i in range(n,-1,-1):
#         f,s,ki,isPossible = i,n,k-2,True
#         # print("S",f,s,ki,ans)
#         while ki>0:
#             ki -= 1
#             bf = s-f
#             s = f
#             f = bf
#             # print(f,s,ki)
#             if f>s or f<0 or s<0:
#                 isPossible = False
#                 break

#         if ki<=0 and isPossible: ans += 1
#     return ans

def funC():
    n,k = list(map(int,input().split(" ")))
    a = list(map(int,input().split(" ")))
    toJump,smallest,i = 0,1,0
    while k:
        k -= 1
        while i<len(a) and smallest+toJump>=a[i]:
            toJump += 1
            i += 1
        smallest = smallest+toJump
    return smallest

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f):
t = int(input())
while t>0:
    t -= 1
    # print(funA())
    # print(funB())
    print(funC())
