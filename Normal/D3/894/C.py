def solve():
    n = int(input())
    a = list(map(int,input().split(" ")))
    a.append(0)
    b = [1]
    for i in range(1,n+1):
        d = a[i-1]-a[i]
        if d!=0:
            b.append(d)
            b.append(1)
        else: b[-1] += 1
    b.pop()

    mid = len(b)//2
    b1 = b[:mid]
    b2 = [i for i in reversed(b[mid:])]
    
    # print(b)
    # print(b1)
    # print(b2)
   
    return b1==b2

def getIns():
    for _ in range(int(input())):
        if solve(): print("YES")
        else: print("NO")

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()