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
    n = int(input())
    a = list(map(int,input().split(" ")))
    d = {}
    ignoreList = {}
    for i,ai in enumerate(a):
        # print(i,ai)
        if ai in ignoreList:
            continue
        elif ai not in d:
            d[ai] = (-1,i)
        else:
            commonDiff, lastIndex = d[ai]
            if commonDiff==-1:
                d[ai] = (i-lastIndex,i)
            elif commonDiff==i-lastIndex:
                d[ai] = (commonDiff,i)
            else:
                ignoreList[ai] = 0
                d.pop(ai)
    # print(d)
    print(len(d))
    for key,value in sorted(d.items()):
        cd,_ = value
        print(key,max(0,cd))

def getIns():
    # for _ in range(int(input())):
    solve()

    # print(ans)

        # for i in ans: print(i,end=" ")
        # print()

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()