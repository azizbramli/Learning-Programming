'''
/*
 * Copyright(C) 2023, Charles T, <chalodss@proton.me> 
 *
 */
'''

import random
import sys
import time

def search_sequential(elements, val):
    """ sequential search function """
    i = 0

    while elements[i] != val:
        i += 1
    return i

def search_dichotomic(elements, beg, end, val):
    """ dichotomic search function """
    while beg <= end:
        middle = (beg + end) // 2
        if val == elements[middle]:
            return middle
        if val < elements[middle]:
            end = middle - 1
        else:
            beg = middle + 1
    return None

if __name__ == '__main__':
    j           = 0
    NB_TESTS    = int(sys.argv[1])
    LIMIT       = int(sys.argv[2])
    SIZE        = int(sys.argv[3])
    A           = random.sample(range(0, LIMIT), SIZE)
    A.sort()
    B           = A[:]
    to_find     = []

    for j in range(NB_TESTS):
        to_find.append(A[random.randint(0, SIZE)])

    s1 = time.time_ns()
    for j in range(NB_TESTS):
        search_sequential(A, to_find[j])
    s2 = time.time_ns()
    print(s2 - s1)

    s3 = time.time_ns()
    for j in range(NB_TESTS):
        search_dichotomic(B, 0, SIZE, to_find[j])
    s4 = time.time_ns()
    print(s4 - s3)
