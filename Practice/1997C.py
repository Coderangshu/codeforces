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
    n = int(input())
    s = input()
    stk = []
    ans = 0
    carry = 0
    for c in s:
        if c=='(':
            stk.append(c)
        elif c=='_':
            if len(stk)==0 or stk[-1]==')':
                stk.append(c)
            else:
                stk.pop()
                ans += 1
                if len(stk)!=0:
                    carry += 2
        else:
            stk.pop()
            ans += 1+carry
            carry = 0
    return ans

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