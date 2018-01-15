#!/usr/bin/env python

# encoding: utf-8

"""
@author: swensun

@github:https://github.com/yunshuipiao

@software: python

@file: find_peak_element.py

@time: 2018/1/10 21:14

@desc: 寻找一个数据的局部峰值。1.相邻位置的数字是不同的 2.A[0] < A[1] 并且 A[n - 2] > A[n - 1]
        假定P是峰值的位置则满足A[P] > A[P-1]且A[P] > A[P+1]，返回数组中任意一个峰值的位置。

@hint: 最简单的方法：遍历， O(n), Time Limit Exceeded。二分法可解。
"""

def find_peak_element(array):
    length = len(array)
    lo = 0
    hi = len(array) - 1
    while lo < hi:
        mid = (hi + lo) >> 1
        if 0 < mid < length - 1 and array[mid - 1] < array[mid] > array[mid + 1]:
            print(mid)
            return mid
        if array[mid] < array[mid + 1]:
            lo = mid
        else:
            hi = mid

    # return lo


if __name__ == '__main__':
    array_test = [0, 1, 3, 4, 7, 6, 8, 4,  3, 2]
    assert find_peak_element(array_test) in [4, 6]