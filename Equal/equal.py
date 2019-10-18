#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the equal function below.
memory = {}
def f(i, j, nop, rank):
    global memory
    if i == j:
        return 0

    tmp_min = [math.inf]

    local_min = math.inf 
    operatios = []
    for nc in [1, 2, 5]:
        if nop > 0 :
            if i < j :
               # print(rank, i, ".", j,"->", rank + 1, i + nc, ".", j, "[ label=", nc, " ]", ";", sep="")
                str_index = str(i + nc) + "," + str(j)
                if memory.get(""):
                    tmp_m = memory[str_index] 
                else:
                    tmp_m = f(i + nc, j, nop - 1, rank + 1) + 1
                    memory[str_index] =  tmp_m

                tmp_min.append(tmp_m)
            else:
               # print(rank, i,".",j,"->", rank + 1, i ,".", j + nc,"[ label=", nc, " ]",";", sep="")
                str_index = str(i ) + "," + str(j + nc)
                if memory.get(""):
                    tmp_m = memory[str_index] 
                else:
                    tmp_m = f(i , j + nc, nop - 1, rank + 1) + 1
                    memory[str_index] =  tmp_m
    return min(tmp_min)

    

def equal(arr):
    n_op = 0
    for i in range(1, len(arr)):
        n_op = n_op + f(arr[i - 1], arr[i],abs(arr[i - 1] -  arr[i]),0 )
        if i + 1 < len(arr):
            arr[i + 1] = arr[i + 1] + abs(arr[i - 1] -  arr[i])
    print(memory)
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
