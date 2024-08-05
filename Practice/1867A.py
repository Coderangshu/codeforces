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
    a = list(map(int,input().split(" ")))
    ai = [[i,ia] for i,ia in enumerate(a)]
    ai.sort(key=lambda x:-x[1])
    for i in range(1,n+1): ai[i-1].append(i)
    return [c for a,b,c in sorted(ai)]


def getIns():
    for _ in range(int(input())):
        ans = solve()
        for i in ans: print(i,end=" ")
        print()

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()