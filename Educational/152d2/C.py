def solve():
    n,m = list(map(int,input().split(" ")))
    s = input()
    oneCount, sm = [0], 0
    for c in s:
        if c=='1': sm += 1
        oneCount.append(sm)
    prevOne, nextZero,pO, nZ = [0],[],-1,n
    for i,c in enumerate(s):
        prevOne.append(pO)
        if c=='1': pO = i
    for i,c in enumerate(reversed(s)):
        nextZero.append(nZ)
        if c=='0': nZ = n-i-1
    nextZero.append(0)
    nextZero.reverse()
    st = set()
    while m:
        m -= 1
        l,r = list(map(int,input().split(" ")))
        noOf1 = oneCount[r]-oneCount[l-1]
        oneB = r-noOf1+1
        noOf1E = oneCount[r]-oneCount[oneB-1]
        if noOf1==noOf1E: st.add((-1,n+1))
        else: st.add((prevOne[l]+2,nextZero[r]))
    return len(st)

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f):
        
t = int(input())
while t>0:
    t -= 1
    print(solve()) 