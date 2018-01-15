#!/usr/bin/env python

# encoding: utf-8

"""
@author: swensun

@github:https://github.com/yunshuipiao

@software: python

@file: maximum_subarray_one.py

@time: 2018/1/11 21:03

@desc: 求数组的最大子数列和， 时间复杂度 O(n)

@hint: 两种解法。一是分析数组：负数 + 正数 > 正数, 此时最大值就是当前值。 另一种是动态规划，用数组记录子数列的和，空间换时间。
 """

import math


def maximum_subarray_one(array):
    # important
    if array is None or len(array) == 0:
        return 0
    result = -math.inf
    cur_sum = 0
    for i in array:
        if cur_sum <= 0:
            cur_sum = i
        else:
            cur_sum += i
        if cur_sum > result:
            result = cur_sum
    return result

def maximum_subarray_two(array):
    # important
    if array is None or len(array) == 0:
        return 0
    result = -math.inf
    sum_array = array[:] #copy
    for index, _ in enumerate(array):
        if index == 0:
            sum_array[index] = array[index]
        else:
            if sum_array[index - 1] < 0:
                sum_array[index] = array[index]
            else:
                sum_array[index] = array[index] + sum_array[index - 1]
        if sum_array[index] > result:
            result = sum_array[index]
    return max(sum_array)  # result

if __name__ == '__main__':
    a = [1, -2, 3, 10, -4, 7, 2, -5]
    b = [-2, -8, -1, -5, -9]
    c = [2, 8, 1, 5, 9]
    assert maximum_subarray_one(a) == 18
    assert maximum_subarray_one(b) == -1
    assert maximum_subarray_one(c) == 25

    assert maximum_subarray_two(a) == 18
    assert maximum_subarray_two(b) == -1
    assert maximum_subarray_two(c) == 25

