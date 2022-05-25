
from cmath import inf


def getminmax(array, size):
    max = -inf
    min = inf
    for i in range(size):
        if array[i] > max:
            max = array[i]
        if array[i] < min:
            min = array[i]
    return max, min

# APPROACH 2 - divide and conquer
def divide(array, start, end):
    size = end-start + 1
    #sprint(size)
    min = max = 0
    if size == 0 or start > end:
        return min, max
    if size == 1:
        max = min = array[start]
    elif size == 2:
        if array[start]< array[end]:
            min = array[start]
            max = array[end]
        else:
            max = array[start]
            min = array[end]
    else:
        min1, max1 = divide(array, start, start + (end-start)//2)
        min2, max2 = divide(array, start + (end-start)//2 + 1, end)
        min = min1 if min1 < min2 else min2
        max = max1 if max1 > max2 else max2
    #print(min, max)
    return min, max


array = [111,2,320,40,5,6]
size = 6
#max, min= getminmax(array, size)
max, min= divide(array, 0, size-1)

print(max, min)