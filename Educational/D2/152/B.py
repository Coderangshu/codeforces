def solve():
    n,k = list(map(int,input().split(" ")))
    a = list(map(int,input().split(" ")))
    for i,ai in enumerate(a):
        if ai%k==0: a[i] = k
        else: a[i] = ai%k
    pair = [(ai,i) for i,ai in enumerate(a)]
    pair.sort(key=lambda i:(-i[0],i[1]))
    return [i+1 for ai,i in pair]
    

def test():
    t = int(input())
    while t>0:
        t -= 1
        a = solve()
        for i in a:
            print(i,end=" ")
        print()

test()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): test()

