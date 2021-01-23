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
    str_index = str(i) + "," + str(j)

    if memory.get(str_index):
        return memory.get(str_index)
    if i == j:
        memory[str_index] = 0
        return 0

    tmp_min = [math.inf]

    local_min = math.inf 
    operatios = []
    for nc in [1, 2, 5]:
        if nop > 0 :
            if i < j :
                #print(rank, i, ".", j,"->", rank + 1, i + nc, ".", j, "[ label=", nc, " ]", ";", sep="")
                tmp_m = f(i + nc, j, nop - 1, rank + 1) + 1
                tmp_min.append(tmp_m)
            else:
                #print(rank, i,".",j,"->", rank + 1, i ,".", j + nc,"[ label=", nc, " ]",";", sep="")
                str_index = str(i ) + "," + str(j + nc)
                tmp_m = f(i , j + nc, nop - 1, rank + 1) + 1
                tmp_min.append(tmp_m)

    str_index = str(i) + "," + str(j)
    memory[str_index] =  min(tmp_min)
    return min(tmp_min)

    

def equal(arr):
    n_op = 0
   # print("digraph G {")

    arr.sort()
    add_value = 0
    for i in range(1, len(arr)):
        n_op = n_op + f(arr[i - 1], arr[i],abs(arr[i - 1] -  arr[i]),0 )
        add_value += abs(arr[i - 1] -  arr[i])
        if i + 1 < len(arr):
            arr[i + 1] = arr[i + 1] + add_value 
        #for j in range(i + 1, len(arr)):
            #arr[j] = arr[j] + add_value
    #print("}")
    print(n_op)
    return n_op
if __name__ == '__main__':
    sys.setrecursionlimit(10000)
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        n = int(input())

        arr = list(map(int, input().rstrip().split()))

        operations = []
        result = equal(arr)

        fptr.write(str(result) + '\n')

fptr.close()
