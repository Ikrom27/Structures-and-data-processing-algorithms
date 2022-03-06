def get_pattern(string):
    pattern = [0] * len(string)
    idx = 0
    j = 1
    while j < len(string):
        if string[idx] == string[j]:
            pattern[j] = idx + 1
            idx += 1
            j += 1
        else:
            if idx == 0:
                pattern[j] = 0
                j += 1
            elif j > 0:
                idx = pattern[idx - 1]
    return pattern


def search_string(text, string):
    i = 0
    j = 0
    pattern = get_pattern(string)
    while j < len(string):
        if text[i] == string[j]:
            i += 1
            j += 1
        elif j == 0:
            i += 1
        else:
            j = pattern[j-1]
    return i - j


string = input("Print your string here: ")

with open("number_6.txt") as file:
    text = file.read()

print(search_string(text, string))