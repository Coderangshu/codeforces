def solve():
    a = input()
    n = len(a)
    # stk = []
    # for c in a:
    #     if c==')':
    #         if len(stk)>0 and stk[-1]=='(': stk.pop()
    #         else: stk.append(c)
    #     else: stk.append(c)
    # if len(stk)==0: return [False]
    # isOpposite = False
    # for i in range(n-1):
    #     seg = a[i:i+2]
    #     if seg=="()": continue
    #     elif seg==")(":
    #         isOpposite = True
    #         break
    # ans = ""
    # if isOpposite:
    ans1 = ans2 = ""
    for i in range(n): ans1 += "("
    for i in range(n): ans1 += ")"
    # else:
    for i in range(n): ans2 += "()"
    if ans1.find(a)==-1: return [True,ans1]
    if ans2.find(a)==-1: return [True,ans2]
    return [False]



def getIns():
    for _ in range(int(input())):
        a = solve()
        if a[0]:
            print("YES")
            print(a[1])
        else:
            print("NO")

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()