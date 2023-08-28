def solve():
    n = int(input())
    p = list(map(int,input().split(" ")))
    cnt = 0
    for i,e in enumerate(p):
        if i+1==e: cnt += 1
    return (cnt+1)//2

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f):
        
t = int(input())
while t > 0:
    t -= 1
    print(solve())
