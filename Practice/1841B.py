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
    q = int(input())
    a = []
    secondPart = False
    for xi in map(int,input().split()):
        if len(a)==0 or a[-1]<=xi:
            if not secondPart or (secondPart and xi<=a[0]):
                a.append(xi)
                print(1,end="")
            else: print(0,end="")
        elif xi<a[-1]:
            if not secondPart and xi<=a[0]:
                secondPart = True
                a.append(xi)
                print(1,end="")
            else: print(0,end="")
    
        # print(a)
    print()
            



def getIns():
    for _ in range(int(input())): solve()

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()