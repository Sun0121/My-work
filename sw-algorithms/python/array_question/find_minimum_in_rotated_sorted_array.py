#!/usr/bin/env python

# encoding: utf-8

"""
@author: swensun

@github:https://github.com/yunshuipiao

@software: python

@file: find_minimum_in_rotated_sorted_array.py

@time: 2018/1/15 09:42

@desc: 寻找旋转排序数组中的最小值。

@hint: 二分查找，注意条件比较。
"""


#假设数组不重复
def find_minimum_in_rotated_sorted_array(array):
    #参数合法性
    if array is None or len(array) == 0:
        return -1
    i = 0
    j = len(array) - 1
    while i < j:
        mid = (i + j) >> 1
        if array[mid] >= array[i] and array[mid] > array[j]:
            i = mid + 1
        else:
            j = mid
    return array[i]

# 假设数组有重复, 上面算法一样适用。

if __name__ == '__main__':
    a = [2, 3, 4, 5, 6, 1]
    print(find_minimum_in_rotated_sorted_array(a))