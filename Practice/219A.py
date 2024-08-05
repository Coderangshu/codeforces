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
    k = int(input())
    s = input()
    d = {}
    for c in s:
        d[c] = d.get(c,0)+1
    # print(d)
    ans = ""
    for key,val in d.items():
        if val%k!=0:
            return -1
        ans += key*(val//k)
    return ans*k


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