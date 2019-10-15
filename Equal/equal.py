#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the equal function below.
operations = []
def are_equal(A):
    init_a =A[0]
    for i in A:
        if i != init_a:
            return 0
    return 1

def f(i, j, nop):
    if i == j:
        return 0

    tmp_min = [math.inf]
    distributed_c = 0
    C = [1, 2, 5]
    for nc in [1, 2, 5]:
        if nop > 0 :
            if i < j :
                tmp_min.append(f(i + nc, j, nop - 1) + 1)
            else:
                tmp_min.append(f(i , j + nc, nop - 1) + 1)
        else:
            return 0
    op_index = tmp_min.index(min(tmp_min))
    operations.append(C[op_index - 1])
    return min(tmp_min)

    

def equal(arr):
    i = 3
    j = 8 
    print(f(i, j, j - i), operations)
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        n = int(input())

        arr = list(map(int, input().rstrip().split()))

        operations = []
        result = equal(arr)

        fptr.write(str(result) + '\n')

fptr.close()
