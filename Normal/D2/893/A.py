def solve():
    a,b,c = list(map(int,input().split(" ")))
    if c%2==0:
        return "First" if a>b else "Second"
    else:
        b -= 1
        return "First" if a>b else "Second"

def getIns():
    for _ in range(int(input())):
        print(solve())

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()