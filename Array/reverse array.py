# Write a program to reverse an array or string

def reverse1(array, start, end):
    for i in range(start, (end-start)//2 + 1):
        temp = array[start + i]
        array[start+i] = array[end-i]
        array[end-i] = temp
    

def reverse2(arr, start, end):
    if start >= end:
        return
    arr[start], arr[end] = arr[end], arr[start]
    reverse2(arr, start+1, end-1)

arr = [1,2,3,4,5]
reverse2(arr, 0, len(arr)-1)
print(arr)