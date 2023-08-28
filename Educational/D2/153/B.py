def solve():
    m,k,a1,ak = list(map(int,input().split(" ")))
    taken1,takenk = m%k,m//k
    takenF1,takenFk = max(0,taken1-a1), max(0,takenk-ak)
    left1 = max(0,a1-taken1)
    replacekwith1 = min(left1//k,takenFk)
    return takenF1+takenFk-replacekwith1

def getIns():
    for _ in range(int(input())):
        print(solve())

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()