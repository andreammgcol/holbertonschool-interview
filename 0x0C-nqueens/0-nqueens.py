#!/usr/bin/python3
""" Program that solves the N queens problem """

import sys


def display(chessboard):
    """ print chessboard"""
    solve = []
    for row in range(len(chessboard)):
        for col in range (len(chessboard)):
            if chessboard[row][col]:
                solve.append([row,col])
    print(solve)

def check(chessboard, row, col, n):
    """check if a queen can be placed on chessboard"""
    for i in range(col):
        if chessboard[row][i] == 1:
            return False

    for j, i in zip(range(row, -1, -1), range(col, -1, -1)):
        if chessboard[j][i] == 1:
            return False
    
    for j, i in zip(range(row, n, 1), range(col, -1, -1)):
        if chessboard[j][i] == 1:
            return False

    return True


def solve(chessboard, col, n):
    if col == n:
        display(chessboard)
        return True

    i = False
    for k in range(n):
        if check(chessboard, k, col, n):
            chessboard[k][col] = 1
            i = solve(chessboard, col + 1, n) or i
            chessboard[k][col] = 0
    return i

if __name__ == "__main__":

    if len(sys.argv) != 2:
        print('Usage: nqueens N')
        exit(1)

    try:
        n = int(sys.argv[1])

    except ValueError:
        print('N must be a number')
        exit(1)

    if n < 4:
        print('N must be at least 4')
        exit(1)

    chessboard = [[0 for i in range(n)] for j in range(n)]
    solve(chessboard, 0, n)
