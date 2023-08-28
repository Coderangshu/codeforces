def solve():
    a = list(map(int,input().split(" ")))

def getIns():
    for _ in range(int(input())):
        print(solve())

# getIns()

from contextlib import redirect_stdout
with open('out.txt', 'w') as f:
    with redirect_stdout(f): getIns()