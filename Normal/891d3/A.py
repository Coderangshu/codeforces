def solve():
    n = int(input())
    a = list(map(int,input().split(" ")))
    # ce, co = 0,0
    # for i in a:
    #     if i%2==0: ce += 1
    #     else: co += 1
    # if abs(co-ce)%2==0: return "YES"
    # else: return "NO"
    if sum(a)%2==0: return "YES"
    return "NO"

def getIns():
    t = int(input())
    while t > 0:
        t -= 1
        print(solve())

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()