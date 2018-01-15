#!/usr/bin/env python

# encoding: utf-8

"""
@author: swensun

@github:https://github.com/yunshuipiao

@software: python

@file: contains_duplicate.py

@time: 2018/1/9 23:33

@desc: 判断是否含有重复元素

@hint: 简单不多讲，建议看看相关列表，集合源码
"""


def contains_duplicate(array):
    s = set()
    for a in array:
        if a in s:
            return True
        s.add(a)
    return False


if __name__ == '__main__':
    array_test_one = [1, 2, 3, 4, 5]
    assert (contains_duplicate(array_test_one) == False)
    array_test_two = [1, 2, 1, 4, 5]
    assert (contains_duplicate(array_test_two) == True)
