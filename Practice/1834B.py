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
    a,b = list(map(str,input().split(" ")))
    na,nb = len(a),len(b)
    n = max(na,nb)
    if na!=nb:
        d = abs(na-nb)
        if na<nb: a = "".join(["0"]*d)+a
        else: b = "".join(["0"]*d)+b
    i = 0
    while i<n:
        if a[i]!=b[i]: break
        i += 1
    return abs(int(a[i])-int(b[i]))+9*(n-i-1) if i<n else 0




def getIns():
    for _ in range(int(input())):
        ans = solve()

        print(ans)

        # for i in ans: print(i,end=" ")
        # print()

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()