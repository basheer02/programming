def solve_n_queens(n):
    def backtrack(board, row, result):
        if row == n:
            result.append(["".join(row) for row in board])
            return
        for col in range(n):
            if all(
                board[i][col] == "."
                for i in range(row)
            ) and all(
                board[row][i] == "."
                for i in range(col)
            ) and all(
                board[row][i] == "."
                for i in range(col+1, n)
            ) and all(
                board[i][col-i+row] == "."
                for i in range(min(row, n-col))
            ) and all(
                board[row-i][col-i+row] == "."
                for i in range(min(row, col)+1)
            ):
                board[row][col] = "Q"
                backtrack(board, row+1, result)
                board[row][col] = "."
                
    result = []
    board = [["."]*n for _ in range(n)]
    backtrack(board, 0, result)
    return result

print(solve_n_queens(4))

n = 4
board = [["."]*n for _ in range(n)]
print(board)