def solve():
    ans,a = "",-1
    for i in range(8):
        l = input()
        for j,c in enumerate(l):
            if 'a'<=c<='z':
                a = j
                break
        if a!=-1 and l[a]!='.': ans += l[a]
    return(ans)

def getIns():
    for _ in range(int(input())):
        print(solve())

# getIns()

from contextlib import redirect_stdout
with open('out.txt', 'w') as f:
    with redirect_stdout(f): getIns()