import random


def binarsearch(arr, key):
    middle = len(arr)//2    # Обозначает середину массива
    if len(arr) == 1 and arr[middle] != key:
        return None
    elif arr[middle] == key:
        return arr[middle]
    elif arr[middle] < key:
        return binarsearch(arr[middle:], key)
    elif arr[middle] > key:
        return binarsearch(arr[:middle], key)


def fill(method, n):
    global arr
    min_number = random.randint(n * -1, n)
    if method == 0:
        while n > 0:
            min_number = random.randint(min_number + 1, min_number + 10)
            arr.append(min_number)
            n -= 1
    elif method == 1:
        while n > 0:
            min_number = random.randint(min_number - 5, min_number - 1)
            arr.append(min_number)
            n -= 1
    else:
        while int(n) > 0:
            arr.append(random.randint(n * -1, n))
            n -= 1


n = int(input("Print size: "))
key = int(input("print keyword: "))
method = int(input(" 0 - sort array + , 1 - sort array -, 2 - random: "))
#arr = []
#fill(method, n)
arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13]

print(arr)
print(binarsearch(arr, key))