'''
/*
 * Copyright(C) 2023, Charles T, <chalodss@proton.me> 
 *
 */
'''

import random
import sys
from timeit import timeit

SETUP = """
from functools import reduce
from __main__ import bubble_sort
from __main__ import quick_sort
from __main__ import A
from __main__ import B
from __main__ import nb
"""

def bubble_sort(elements):
    """ bubble sort algorithm """
    i = len(elements) - 1
    j = 0

    while i > 0:
        while j < i:
            if elements[j] > elements[j + 1]:
                elements[j], elements[j + 1] = elements[j + 1], elements[j]
            j += 1
        j = 0
        i -= 1

def partition(elements, left, right):
    """ partition function """
    i = left - 1
    j = right
    k = elements[right]

    while i < j:
        i += 1
        while elements[i] < k:
            i += 1
        j -= 1
        while j > 0 and elements[j] > k:
            j -= 1
        if i < j:
            elements[i], elements[j] = elements[j], elements[i]
    elements[i], elements[right] = elements[right], elements[i]
    return i

def quick_sort(elements, left, right):
    """ quick sort algorithm """
    pivot = 0

    if left < right:
        pivot = partition(elements, left, right)
        quick_sort(elements, left, pivot - 1)
        quick_sort(elements, pivot + 1, right)

if __name__ == '__main__':
    INF_BOUND   = int(sys.argv[1])
    UPPER_BOUND = int(sys.argv[2])
    LIST_SIZE   = int(sys.argv[3])
    NB          = int(sys.argv[4])

    A = random.sample(range(INF_BOUND, UPPER_BOUND), LIST_SIZE)
    B = A[:]
    #print("Before:      ", A)
    print(f"Bubble sort : {timeit('bubble_sort(A)', setup=SETUP, number=NB):.3f}")
    #print("After:       ", A, "\n\n")
    #print("Before:      ", B)
    print(f"Quick sort  : {timeit('quick_sort(B, 0, len(B) - 1)', setup=SETUP, number=NB):.3f}")
    #print("After:       ", B)
