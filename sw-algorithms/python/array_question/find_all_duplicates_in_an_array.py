#!/usr/bin/env python

# encoding: utf-8

"""
@author: swensun

@github:https://github.com/yunshuipiao

@software: python

@file: find_all_duplicates_in_an_array.py

@time: 2018/1/13 15:55

@desc:  寻找数组中的全部重复元素(1 <= array[i] <= n), 数组中的元素都大于1， 小于元素个数。

@hint: 由于数组的特殊性。新建同样大小的数组。将出现数字对应的下标标记，最后看出现次数。
        比如[2, 1, 2]中，2出现，将新数组下标为2标记为0， 后面遇到查看为0，说明重复。
"""

def find_all_duplicates_in_an_array_one(array):
    # copy array
    result = []
    temp_array = array[:]
    for value in array:
        if temp_array[value - 1] == 0:
            result.append(value)
        else:
            temp_array[value - 1] = 0
    print(result)
    return list(set(result))

def find_all_duplicates_in_an_array_tow(array):
    #改进：上面使用了一个临时数组来做标记，可以将其取消，节省空间。
    #方法：因为都是正数，所以可以参照方法1， 将出现过的数字取反成负数，若后面在入到负数，则说明重复。
    result = []
    for value in array:
        index = abs(value) - 1
        if array[index] < 0:
            result.append(abs(value))
        array[index] = -array[index]
    print(result)
    return list(set(result))


if __name__ == '__main__':
    a = [1, 4, 3, 5, 8, 3, 5, 3]
    assert find_all_duplicates_in_an_array_one(a) == [3, 5]
    b = [1, 4, 3, 5, 7, 3, 5, 3]
    assert find_all_duplicates_in_an_array_tow(b) == [3, 5]
