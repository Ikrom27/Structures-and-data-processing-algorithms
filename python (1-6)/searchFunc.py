import random


def search(arr, key):
    for i in range(len(arr)):
        if arr[i] == key:
            return i
    return "No key"


n = int(input("Print size: "))
key = input("print keyword: ")
method = int(input(" 0 - sort array + , 1 - sort array -, 2 - random: "))
arr = []
minRandomNumber = random.randint(n * -1, n)

if method == 0:
    while n > 0:
        minRandomNumber = random.randint(minRandomNumber + 1, minRandomNumber + 10)
        arr.append(minRandomNumber)
        n -= 1
elif method == 1:
    while n > 0:
        minRandomNumber = random.randint(minRandomNumber - 5, minRandomNumber - 1)
        arr.append(minRandomNumber)
        n -= 1
else:
    while int(n) > 0:
        arr.append(random.randint(n * -1, n))
        n -= 1
print(search(arr, key))
print(arr)
