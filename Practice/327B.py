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

def modifiedEratosthenesSieve():
    # a = list(map(int,input().split(" ")))
    n = int(input())
    MAX_SIZE = 2000001
    isPrime, prime, smallestPrimeFactor = [True]*MAX_SIZE, [], [None]*MAX_SIZE

    isPrime[0] = isPrime[1] = False

    for i in range(2,MAX_SIZE):
        if isPrime[i]:
            prime.append(i)
            if len(prime)==n:
                return prime
            smallestPrimeFactor[i] = i
        
        j = 0
        while j<len(prime) and i*prime[j]<MAX_SIZE and prime[j]<=smallestPrimeFactor[i]:
            isPrime[i*prime[j]] = False
            smallestPrimeFactor[i*prime[j]] = prime[j]
            j += 1
    return prime

def solve():
    n = int(input())
    tenPower = 0
    tn = n
    while n>0:
        n //=10
        tenPower += 1
    # tenPower -= 1
    # print(5*10**tenPower)
    return ([3*10**tenPower+i for i in range(tn)])

def getIns():
    # for _ in range(int(input())):
    ans = solve()

    for i in ans:
        print(i,end=" ")

        # for i in ans: print(i,end=" ")
        # print()

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()