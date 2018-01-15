#!/usr/bin/env python

# encoding: utf-8

"""
@author: swensun

@github:https://github.com/yunshuipiao

@software: python

@file: rotate_image.py

@time: 2018/1/14 20:33

@desc: 二维数组旋转90， 180， 270度。

@hint: 找规律，下标值的关系。另外参考旋转数组。可以先对角线旋转， 后水平旋转。in place
"""

#找旋转的坐标规律, 注意下标， 不要多转。最后一个不用转
def rotate_image_one(array):
    n = len(array)
    i = 0
    j = 0
    while i < (n >> 1):
        j = i
        while j < (n - 1 - i):
            temp_value = array[i][j]
            array[i][j] = array[n - 1 - j][i]
            array[n - 1 - j][i] = array[n - 1 - i][n - 1 - j]
            array[n - 1 - i][n - 1 - j] = array[j][n - 1 - i]
            array[j][n - 1 - i] = temp_value
            j += 1
        i += 1

#对角旋转，后水平旋转， 还是下标计算。
def rotate_image_two(array):
    n = len(array)
    for i in range(n):
        for j in range(i + 1):
            array[i][j], array[j][i] = array[j][i], array[i][j]
    for i in range(n):
        for j in range(n >> 1):
            # temp = array[i][j]
            # array[i][j] = array[i][n-1-j]
            # array[i][n-1-j] = temp
            array[i][j], array[i][n-1-j] = array[i][n-1-j], array[i][j]

if __name__ == '__main__':
    a = [[1,2,3,4], [5,6,7,8], [9,10, 11,12], [13,14,15,16]]
    rotate_image_one(a)
    for i in a:
        print(i)
