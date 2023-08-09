def funA():
    n,m,k,H = list(map(int,input().split(" ")))
    h = list(map(int,input().split(" ")))
    ans = 0
    for i in h:
        d = abs(H-i)
        if d!=0 and d%k==0:
            if d//k<m: ans += 1
    return ans

def funB():
    n = int(input())
    a = list(map(int,input().split(" ")))
    if n==1: return "YES"
    sa = sorted(a)
    for e,se in zip(a,sa):
        if (e%2==0 and se%2!=0) or (e%2!=0 and se%2==0):
            return "NO"
    return "YES"

def funC():
    n,k = list(map(int,input().split(" ")))
    c = list(map(int,input().split(" ")))
    l,f,cnt1,cnt2 = -1,n,0,0
    for i in range(n):
        if c[i]==c[0]:
            cnt1 += 1
            if cnt1==k:
                l = i
                break
    for i in range(n-1,-1,-1):
        if c[i]==c[-1]:
            cnt2 += 1
            if cnt2==k:
                f = i
                break
    if l!=-1 and f!=n and (c[0]==c[-1] or l<=f): return "YES"
    return "NO"

def funD():
    n = int(input())
    a = list(map(int,input().split(" ")))
    a = [0]+a
    ln, extra = [-1]*n, []
    for i in range(1,n):
        diff = a[i]-a[i-1]
        if diff<=n:
            if ln[diff-1]==-1: ln[diff-1] = diff
            else: extra.append(diff)
        else: extra.append(diff)
        if len(extra)>1: return "NO"
    li = [i+1 for i,j in enumerate(ln) if j==-1]
    if len(extra)==0 and len(li)==1: return "YES"
    sm = sum(li)
    return "YES" if sm==extra[0] else "NO"

# def funF():
#     n,k = list(map(int,input().split(" ")))
#     a = list(map(int,input().split(" ")))
#     ans = float("-inf")
#     for ii,i in enumerate(a[0:-2]):
#         for j in a[ii+1:]:
#             lo,hi = 0,2**k-1
#             while lo<=hi:

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f):
t = int(input())
while t>0:
    t -= 1
    # print(funA())
    # print(funB())
    # print(funC())
    print(funD())