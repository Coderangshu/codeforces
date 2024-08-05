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
    n,k,q = list(map(int,input().split(" ")))
    a = list(map(int,input().split(" ")))
    segments = []
    count = 0
    for i in a:
        if i<=q: count += 1
        else:
            if count!=0: segments.append(count)
            count = 0
    if count!=0: segments.append(count)
    # print(segments)
    ans = 0
    for i in segments:
        if i>=k:
            j = i-(k-1)
            ans += j*(j+1)//2
    return ans

def getIns():
    for _ in range(int(input())):
        print(solve())

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()