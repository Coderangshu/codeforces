def solve():
    b,c,h = list(map(int,input().split(" ")))
    b -= 2
    m = c+h
    # bread is limit
    if b<m-1:
        return 2+b+(b+1)
    else:
        return 2+m+(m-1)

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f):
        
t = int(input())
while t > 0:
    t -= 1
    print(solve())
