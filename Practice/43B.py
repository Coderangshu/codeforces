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
    ip = input()
    op = input()
    ipa,opa = [0]*128,[0]*128

    for c in ip:
        if c!=" ":
            ipa[ord(c)] += 1
    for c in op:
        if c!=" ":
            opa[ord(c)] += 1
    # print(ipa,opa)
    for i in range(128):
        if opa[i]>ipa[i]:
            return "NO"
    return "YES"

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