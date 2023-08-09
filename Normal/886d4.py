from contextlib import redirect_stdout
import math


# with open('out.txt', 'w') as f:
#     with redirect_stdout(f):
t = int(input())
while t>0:
    t -= 1
    # l = list(map(int,input().split(" ")))
    # l.sort()
    # if l[-1]+l[-2]>=10:
    #     print("YES")
    # else: print("NO")



    # n = int(input())
    # q,ans = float("-inf"),0
    # for i in range(1,n+1):
    #     a,b = list(map(int,input().split(" ")))
    #     if a<=10:
    #         if b>q:
    #             q = b
    #             ans = i
    # print(ans)




    # ans,a = "",-1
    # for i in range(8):
    #     l = input()
    #     for j,c in enumerate(l):
    #         if 'a'<=c<='z':
    #             a = j
    #             break
    #     if a!=-1 and l[a]!='.': ans += l[a]
    # print(ans)



    # n,k = list(map(int,input().split(" ")))
    # l = list(map(int,input().split(" ")))
    # l.sort()
    # takeSegStart = 0
    # takeSegLen = float("-inf")
    # for i in range(1,n):
    #     if l[i]-l[i-1]>k:
    #         takeSegLen = max(takeSegLen,i-takeSegStart)
    #         takeSegStart = i
    # takeSegLen = max(takeSegLen,n-takeSegStart)
    # print(n-takeSegLen)





    # n,c = list(map(int,input().split(" ")))
    # l = list(map(int,input().split(" ")))
    # lo,hi = 0,10**10
    # while lo<=hi:
    #     m = (lo+hi)>>1
    #     tot = 0
    #     for e in l: tot += (e+2*m)**2
    #     if tot<c: lo = m+1
    #     else: hi = m-1
    # print(lo)





    n = int(input())
    l = list(map(int,input().split(" ")))
    cnt, freq = [0]*(n+1),[0]*(n+1)
    for e in l:
        if e<=n: cnt[e] += 1
    for i in range(n+1):
        if cnt[i]>0:
            for j in range(i,n+1,i):
                freq[j] += cnt[i]
    print(max(freq))