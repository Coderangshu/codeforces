# explanation : https://youtu.be/KW_pyUjgZrU

def solve():
    n,k = list(map(int,input().split(" ")))
    a = list(map(int,input().split(" ")))
    toJump,smallest,i = 0,1,0
    while k:
        k -= 1
        while i<len(a) and smallest+toJump>=a[i]:
            toJump += 1
            i += 1
        smallest = smallest+toJump
    return smallest

def getIns():
    for _ in range(int(input())):
        print(solve())

# getIns()

from contextlib import redirect_stdout
with open('out.txt', 'w') as f:
    with redirect_stdout(f): getIns()