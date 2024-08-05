# character to num
def ctn(c: chr) -> int:
    return ord(c)-ord('a') if 'a'<=c<='z' else ord(c)-ord('A')

# num to character
def ntc(n: int, isSmall: bool) -> chr:
    n += ord('a') if isSmall else ord('A')
    return chr(n)

###################################################################################

# ctn -> character to num
# ntc -> num to character

def solve():
    n = int(input())
    ds = []
    for _ in range(n):
        di,si = list(map(int,input().split(" ")))
        ds.append((di,si))
    ds.sort()
    mx = ds[0][0]+(ds[0][1]-1)//2
    
    # print(ds)

    for d,s in ds[1:]:
        if d<mx:
            mx = min(mx,d+(s-1)//2)
        else: break
    return mx



def getIns():
    for _ in range(int(input())):
        print(solve())

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()