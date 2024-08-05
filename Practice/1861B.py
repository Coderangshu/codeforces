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
    a = input()
    b = input()
    for i in range(len(a)-1):
        if a[i]==b[i] and a[i+1]==b[i+1] and a[i]=="0" and a[i+1]=="1": return "YES"
    return "NO"

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