def solve():
    pass

from contextlib import redirect_stdout
with open('out.txt', 'w') as f:
    with redirect_stdout(f):
        
        t = int(input())
        while t>0:
            t -= 1
            print(solve())