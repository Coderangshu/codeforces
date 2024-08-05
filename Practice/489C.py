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
    m,s = list(map(int,input().split(" ")))
    if m>1 and s<=0 or m==1 and s>9 or s>9*m:
        print("-1 -1")
        return
    
    noOf9s = s//9
    non9s = s%9
    # print(noOf9s,non9s)
    noOf9sPow10 = 10**noOf9s

    if m==noOf9s:
        largest = noOf9sPow10-1
    else:
        largest = (noOf9sPow10-1)*10+non9s
        largest *= 10**(m-noOf9s-1)
        largest = int(largest)

    powOf10 = 10**(m-1)
    if m-noOf9s>1:
        smallest = powOf10+(max(non9s-1,0))*noOf9sPow10
        smallest += (8*10**(noOf9s-1)+10**(noOf9s-1)-1) if (non9s==0) else (noOf9sPow10-1)
    else:
        smallest = powOf10*non9s+(noOf9sPow10-1)

    smallest = int(smallest)

    print(smallest, largest)

def getIns():
    # for _ in range(int(input())):
    ans = solve()

    # print(ans)

        # for i in ans: print(i,end=" ")
        # print()

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()