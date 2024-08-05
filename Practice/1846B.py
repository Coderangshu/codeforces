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
    board = []
    for _ in range(3): board.append(input())
    for i in range(3):
        if board[i][0]==board[i][1]==board[i][2] and board[i][0]!='.': return board[i][0]
    for i in range(3):
        if board[0][i]==board[1][i]==board[2][i] and board[0][i]!='.': return board[0][i]
    if board[0][0]==board[1][1]==board[2][2] and board[0][0]!='.': return board[0][0]
    elif board[0][2]==board[1][1]==board[2][0] and board[2][0]!='.': return board[1][1]
    else: return "DRAW"

def getIns():
    for _ in range(int(input())):
        print(solve())

getIns()

# from contextlib import redirect_stdout
# with open('out.txt', 'w') as f:
#     with redirect_stdout(f): getIns()