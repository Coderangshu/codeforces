# character to num
def ctn(c: chr) -> int:
    return ord(c)-ord('a') if 'a'<=c<='z' else ord(c)-ord('A')

# num to character
def ntc(n: int, isSmall: bool) -> chr:
    n += ord('a') if isSmall else ord('A')
    return chr(n)

def solve():
    n,k = list(map(int,input().split(" ")))
    s = input()
    if k%2==0: return "".join(sorted(s))
    count = [[0,0] for _ in range(26)]
    for i,c in enumerate(s): count[ctn(c)][i%2] += 1

    ans = ""
    for i in range(n):
        for j in range(26):
            if count[j][i%2]>0:
                ans += ntc(j,True)
                count[j][i%2] -= 1
                break
    return ans



def getIns():
    for _ in range(int(input())):
        print(solve())

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()