import random

#sort1
def quickSort(arr, min, max):
    if min >= max:
        return arr
    element = max
    i = min
    while i < element:
        if arr[i] > arr[element]:
            arr[i], arr[element] = arr[element], arr[i]
            arr[i], arr[element-1] = arr[element-1], arr[i]
            element -= 1
        else:
            i += 1
    arr = quickSort(arr, min, element-1)
    arr = quickSort(arr, element, max)
    return arr


n = input("Print N: ")
n = int(n)
arr = []

while int(n) > 0:
    arr.append(random.randint(-1000000, 1000000))
    n -= 1

print(quickSort(arr, 0, len(arr)-1))