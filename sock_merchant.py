#!/bin/python3

import os

# Complete the sockMerchant function below.
def sockMerchant(n, ar):
    ar = sorted(ar,key=int)
    cnt = 0
    i = 0
    while (i < (n-1)):
        if(ar[i] == ar[i+1]):
            cnt+=1
            i+=1
        i+=1
    return cnt

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    ar = list(map(int, input().rstrip().split()))

    result = sockMerchant(n, ar)

    fptr.write(str(result) + '\n')

    fptr.close()

