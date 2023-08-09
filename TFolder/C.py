def solve():
    pass

def getIns():
    t = int(input())
    while t > 0:
        t -= 1
        print(solve())


from contextlib import redirect_stdout
with open('out.txt', 'w') as f:
    with redirect_stdout(f): getIns()