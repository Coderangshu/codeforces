# explanation: https://youtu.be/wtmrAXuVGcI
def solve():
    n = int(input())
    ans = 0
    for i in range(1,n+1):
        if n%i==0: ans += 1
        else: break
    return ans

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f):
        
t = int(input())
while t>0:
    t -= 1
    print(solve())