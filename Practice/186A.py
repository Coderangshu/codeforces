import sys
sys.set_int_max_str_digits(0)

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
    # a = list(map(int,input().split(" ")))
    a = input()
    b = input()
    na,nb = len(a),len(b)
    if na<2 or nb<2 or na!=nb:
        return "NO"
    differentLetters = []
    for i in range(na):
        if a[i]!=b[i]:
            differentLetters.append(i)
    if len(differentLetters)!=2:
        return "NO"
    else:
        return "YES" if a[differentLetters[0]]==b[differentLetters[1]] and b[differentLetters[0]]==a[differentLetters[1]] else "NO"


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