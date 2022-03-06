import random


def selectionSort(arr):
    for i in range(len(arr)-1):
        for j in range(i+1, len(arr)):
            if arr[j] < arr[i]:
                arr[j], arr[i] = arr[i], arr[j]
    return arr


n = input("Print N: ")
n = int(n)
arr = []

while int(n) > 0:
    arr.append(random.randint(1000000, 1000000))
    n -= 1

print(selectionSort(arr))