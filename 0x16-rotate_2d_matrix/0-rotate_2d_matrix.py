#!/usr/bin/python3
""" Rotate 2D Matrix
"""


def rotate_2d_matrix(matrix):
    """ Rotate """
    matrix.reverse()
    temp = [row.copy() for row in matrix]

    for x, row in enumerate(temp):
        for y, n in enumerate(row):
            matrix[y][x] = temp[x][y]
