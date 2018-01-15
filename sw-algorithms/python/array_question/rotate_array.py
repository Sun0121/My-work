#!/usr/bin/env python
# encoding: utf-8

"""
@author: swensun

@github:https://github.com/yunshuipiao

@software: python

@file: RotateArray.py

@time: 2018/1/9 16:50

@desc: 旋转数组：将一个数组旋转k次。比如[1, 2 ,3, 4, 5, 6, 7] 旋转 3 次， 得到[5, 6, 7, 1, 2 ,3, 4]。

@hint：空间复杂度O(1), 就地旋转
"""


def rotate(array, k):
    length = len(array)
    if length == 0:
        return
    k = k % length
    swap_one(array, 0, length - 1)
    swap_one(array, 0, k - 1)
    swap_one(array, k, length - 1)
    # 还可以用切片交换
    # array = array[length-k:] + array[:k+1]
    # print(array)


def swap_one(array, start, stop):
    while start < stop:
        array[start], array[stop] = array[stop], array[start]
        start += 1
        stop -= 1


def test():
    array = [1, 2, 3, 4, 5, 6, 7]
    print(array)
    rotate(array, 3)
    print(array)


if __name__ == '__main__':
    test()
