#!/usr/bin/env python

# encoding: utf-8

"""
@author: swensun

@github:https://github.com/yunshuipiao

@software: python

@file: shufflean_array.py

@time: 2018/1/14 22:35

@desc: 洗牌算法。经过洗牌后，保证每一个元素出现在所有位置的概率相等。即随机打乱数组并输出，输出的数组有相同的概率。

@hint: n!种情况其中的一种。
"""
import random

def shufflean_array(array):
    for index, _ in enumerate(array):
        random_index = random.randint(0, index)  #randint(0, n)： 0<=i<=n
        array[index], array[random_index] = array[random_index], array[index]


if __name__ == '__main__':
    a = [i for i in range(10)]
    shufflean_array(a)
    print(a)


