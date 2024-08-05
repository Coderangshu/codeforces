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
    s = input()
    n = len(s)
    if n==1:
        if s[0]=="z":
            return s+"a"
        return s+chr(ord(s[0])+1)
    longestSimilar = (1,0,0)
    i = 0
    while(i<n):
        j = i+1
        while j<n and s[i]==s[j]:
            j += 1
        ml,b,e = longestSimilar
        if ml<j-i+1:
            longestSimilar = (j-i,i,j-1)
        i = j
    l,b,e = longestSimilar
    # print(l,b,e)
    if l==1:
        if s[n-1]=="z":
            return s+"a"
        return s+chr(ord(s[n-1])+1)
    # print(b,e)
    if s[b]=='z':
        s = s[:b+1]+"a"+s[b+1:]
    # print(s[:b+1],chr(ord(s[b])+1),s[b+1:])
    else:
        s = s[:b+1]+chr(ord(s[b])+1)+s[b+1:]
    return s

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