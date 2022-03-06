import random


def merge_sort(arr):
    if len(arr) == 1:
        return arr #если это базовый случай, то возвращаем массив
    right = merge_sort(arr[:len(arr)//2]) #правую часть добавляем массив от нуля до середины
    left = merge_sort(arr[len(arr)//2:]) #левую часть добавляем массив от середины до нуля

    new_arr = []
    i = j = 0

    while i < len(right) and j < len(left): #Добавляем в новый массив меньший из леговго или правого
        if right[i] < left[j]:
            new_arr.append(right[i])
            i += 1
        else:
            new_arr.append(left[j])
            j += 1

    if i < len(right):  #если в новый массив попали не все цифры, то просто заполняем его оставшимеся
        new_arr += right[i:]
    elif j < len(left):
        new_arr += left[j:]
    return new_arr


n = input("Print N: ")
n = int(n)
arr = []

while int(n) > 0:
    arr.append(random.randint(-1000000, 1000000))
    n -= 1
print(merge_sort(arr))