def is_safe(board, row, col, n):
    for i in range(col):
        if board[row][i] == 1:
            return False

    i = row
    j = col
    while i >= 0 and j >= 0:
        if board[i][j] == 1:
            return False
        i = i - 1
        j = j - 1

    i = row
    j = col
    while i < n and j >= 0:
        if board[i][j] == 1:
            return False
        i = i + 1
        j = j - 1

    return True

def solve(board, col, n):
    if col == n:
        return True

    for row in range(n):
        if is_safe(board, row, col, n):
            board[row][col] = 1

            if solve(board, col + 1, n):
                return True

            board[row][col] = 0

    return False

n = int(input("Enter number of queens: "))

board = []
for i in range(n):
    row = []
    for j in range(n):
        row.append(0)
    board.append(row)

if solve(board, 0, n):
    print("Solution:")
    for i in range(n):
        print(board[i])
else:
    print("No solution exists")

# Enter number of queens: 4
# One valid board solution

# def is_safe(board, row, col, n):
#     for i in range(col):
#         if board[row][i] == 1:
#             return False
#     return True

# def solve_n_queens(board, col, n):
#     if col >= n:
#         return True

#     for i in range(n):
#         if is_safe(board, i, col, n):
#             board[i][col] = 1

#             if solve_n_queens(board, col + 1, n):
#                 return True

#             board[i][col] = 0

#     return False


# n = int(input("Enter number of queens: "))
# board = [[0] * n for _ in range(n)]

# if solve_n_queens(board, 0, n):
#     print("Solution:")
#     for row in board:
#         print(row)
# else:
#     print("No solution found")

# 9) Constraint Satisfaction Problem: N-Queens / Graph Coloring
# N-Queens

# Explanation:
# The N-Queens problem places N queens on an N×N board so that no two queens attack each other. Backtracking is used to try placements and undo them if they fail.

# Time Complexity: Worst case O(N!)
# Space Complexity: O(N^2) for board + recursion stack O(N)

# Graph Coloring

# Explanation:
# Graph coloring assigns colors to vertices so that no two adjacent vertices have the same color. It is also solved using backtracking.

# Time Complexity: Worst case exponential, often O(m^V) for m colors and V vertices
# Space Complexity: O(V) or more depending on representation

# Viva Q&A:
# Q1. What is backtracking?
# A technique of trying a solution and undoing it if it fails.

# Q2. What is N-Queens?
# Placing N queens without attacking each other.

# Q3. What is graph coloring?
# Assigning colors so adjacent vertices are different.

# Q4. Where is it used?
# Scheduling, resource allocation, map coloring.