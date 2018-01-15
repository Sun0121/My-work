#!/usr/bin/env python

# encoding: utf-8

"""
@author: swensun

@github:https://github.com/yunshuipiao

@software: python

@file: kth_Largest_element_in_an_array.py

@time: 2018/1/11 23:07

@desc: 寻找数组中的第k大元素， 数组有重复， 重复数据的下标全部输出。涉及最大，最小堆， 优先队列。

@hint: 两种方法：快速排序思想和最大最小堆的思想。
1. 快速排序，看用于比较的那个数前面如果有k-1个元素， 则这个数就是第k大。否则根据下标在左右两边找。
2. 维护一个k大小的小根堆。将剩余元素与堆顶比较，大的丢下面。最后结果是 前k个最大的数构成的小根堆，第k大的数在堆顶。
   （或者维护一个k的大根堆可求第k小的元素， 思想类似。）
3. 复习快速排序和堆排序。
"""


def kth_Largest_element_in_an_array_one(array, k):
    if array is None or len(array) == 0 or k > len(array):
        return -1
    result = part_quick_sort(array, 0, len(array) - 1, k)
    print(result)


def part_quick_sort(array, lo, hi, k):
    temp_value = array[lo]
    start_index = lo
    stop_index = hi
    while start_index < stop_index:
        while start_index < stop_index and array[stop_index] <= temp_value:
            stop_index -= 1
        if start_index < stop_index:
            array[start_index] = array[stop_index]
        while start_index < stop_index and array[start_index] >= temp_value:
            start_index += 1
        if start_index < stop_index:
            array[stop_index] = array[start_index]
    array[start_index] = temp_value
    # start_index: 分界值。如果是是k - 1， 说明这个数就是第k大。
    if start_index == k - 1:
        return array[start_index]
    if start_index > k - 1:
        return part_quick_sort(array, lo, start_index - 1, k)
    else:
        return part_quick_sort(array, start_index + 1, hi, k)


def kth_Largest_element_in_an_array_two(array, k):
    #
    heap_array = array[0: k] #k大小的数组，进行堆化
    last_root_index = (len(heap_array) >> 1) - 1
    for root_index in range(last_root_index, -1, -1):
        small_heap_array(array, root_index, len(array))
    for value in array[k:]:
        if value > heap_array[0]:
            heap_array[0] = value
            small_heap_array(heap_array, 0, len(heap_array))
    print(heap_array[0])


# 快速排序
def quick_sort(array, lo, hi):
    #参数合法性
    if array is None or lo >= hi:
        return
    mid = partition_two(array, lo, hi)
    quick_sort(array, lo, mid - 1)
    quick_sort(array, mid + 1, hi)


def partition_one(array, lo, hi):
    # 以第一个数为基准, 从小到大
    temp_value = array[lo]
    i = lo
    j = hi
    while i < j:
        while i < j and array[j] >= temp_value:
            j -= 1
        if i < j:
            array[i] = array[j]
        while i < j and array[i] <= temp_value:
            i += 1
        if i < j:
            array[j] = array[i]
    array[i] = temp_value
    return i


def partition_two(array, lo, hi):
    i = lo
    j = hi
    while i < j:
        while i < j and array[i] <= array[hi]:
            i += 1
        while i < j and array[j] >= array[hi]: # =保证支点不变，可以后续比较。
            j -= 1
        array[i], array[j] = array[j], array[i]
    array[i], array[hi] = array[hi], array[i]
    return i


#构建最大堆，从小到大排序
def heap_sort_one(array):
    # 最后一个跟节点
    last_node_index = (len(array) >> 1) - 1
    for node_index in range(last_node_index, 0 - 1, -1):  #[llast_node_index .. 0] 的列表
        big_heap_array(array, node_index, len(array))
    # 堆顶最大值和最后一个数互换， 然后堆化数组
    for index in range(len(array) - 1, 0, -1):
        array[0], array[index] = array[index], array[0]
        big_heap_array(array, 0, index)


# 将length个元素，i为节点的数组堆化(i的子节点也都是堆)
def big_heap_array(array, i, length):
    # 左叶子节点
    temp_value = array[i]
    node_index = (i << 1) + 1
    while node_index < length:
        #左右叶子节点的较大值
        if node_index + 1 < length and array[node_index + 1] > array[node_index]:
            node_index = node_index + 1
        # 如果根节点大于叶子节点，说明已经是堆，退出循环。
        if array[node_index] < temp_value:
            break
        array[i] = array[node_index]
        # 调整交换过元素的子节点
        i = node_index
        node_index = (i << 1) + 1
    array[i] = temp_value



#构建最小堆，从大到小排序
def heap_sort_two(array):
    last_node_index = (len(array) >> 1) - 1
    for node_index in range(last_node_index, -1, -1):
        small_heap_array(array, node_index, len(array))
    for index in range(len(array) - 1, 0, -1):
        array[0], array[index] = array[index], array[0]
        small_heap_array(array, 0, index)


def small_heap_array(array, root_index, length):
    temp_root_value = array[root_index]
    node_index = (root_index << 1) + 1
    while node_index < length:
        if node_index + 1 < length and array[node_index + 1] < array[node_index]:
            node_index += 1
        if array[node_index] > temp_root_value:
            break
        array[root_index] = array[node_index]
        root_index = node_index
        node_index = (root_index << 1) + 1
    array[root_index] = temp_root_value



if __name__ == '__main__':
    a = [1, 4, 4, 3, 1, 7, 8, 7]
    quick_sort(a, 0, len(a) - 1)
    print(a)
    # kth_Largest_element_in_an_array_one(a, 3)
    # b = [1, 3, 2, 4, 8, 5, 6, 7]
    # kth_Largest_element_in_an_array_two(b, 3)


