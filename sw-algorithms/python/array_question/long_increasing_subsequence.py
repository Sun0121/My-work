#!/usr/bin/env python

# encoding: utf-8

"""
@author: swensun

@github:https://github.com/yunshuipiao

@software: python

@file: max_increasing_subsequence.py

@time: 2018/1/13 17:24

@desc: 最长递增子序列：指找到一个给定序列的最长子序列的长度，使得子序列中的所有元素单调递增。(下标不相邻).LIC
        { 3，5，7，1，2，8 } 的 LIS 是 { 3，5，7，8 }，长度为 4。

@hint: 一般使用动态规划求解。或者转化为求公共子序列问题。
"""


#动态规划法， O(n^2)时间复杂度。想求的array[0, i]的最大递增子序列。则计算array[0, i- 1]中以各元素为最大元素的最长递增序列。与array[i]比较, 因为不连续。
# 来决定当前array[i]最长递增子序列的值。
def longest_increasing_subsequence_one(array):
    temp_array = [1] * len(array)
    for index, _ in enumerate(array):
        for i in range(0, index):
            if array[i] < array[index] and temp_array[i] + 1 >= temp_array[index]:
                temp_array[index] = temp_array[i] + 1
    return max(temp_array)

#复制列表并排序，求两列表的最长公共子序列( LCS ): 动态规划
def longest_increasing_subsequence_two(array):
    copy_array = array[:]
    copy_array.sort()
    #中间结果
    temp_array = [[0 for i in range(len(array))] for j in range(len(copy_array))]
    for i in range(1, len(array)):
        for j in range(1, len(copy_array)):
            if array[i] == copy_array[j]:
                temp_array[i][j] = temp_array[i - 1][j - 1] + 1
            else:
                temp_array[i][j] = max(temp_array[i][j - 1],  temp_array[i - 1][j])
    #倒推求出最长公共子序列
    result = []
    i = len(array) - 1
    j = len(copy_array) - 1
    while i > 0 and j > 0:
        if array[i] == copy_array[j]:
            result.append(array[i])
            i -= 1
            j -= 1
        else:
            if temp_array[i][j - 1] >= temp_array[i - 1][j]:
                j -= 1
            else:
                i -= 1
    result.reverse()
    print(result)
    print(len(result))






if __name__ == '__main__':
    a = [1, 6, 4, 3, 5, 1, 2, 3, 4, 1]
    longest_increasing_subsequence_two(a)
