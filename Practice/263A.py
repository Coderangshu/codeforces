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
    ans = 0
    for i in range(5):
        a = list(map(int,input().split(" ")))
        asum = sum(a)
        if asum>0:
            ans += abs(2-i)
            for j in range(5):
                if a[j]==1:
                    ans += abs(2-j)
                    break
            break

    return ans

def getIns():
    # for _ in range(int(input())):
    ans = solve()

    print(ans)

        # for i in ans: print(i,end=" ")
        # print()

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()