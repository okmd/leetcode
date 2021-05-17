# https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1
# https://www.geeksforgeeks.org/array-rotation/
import array
'''
Method 1: Rotation by temp array. time=O(n), space=O(d)
    -> store first d elements in the temp array.
    -> rotate the remaining array.
    -> place back the temp array.
'''


def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


def show(arr, msg=""):
    print(msg, end=": ")
    for i in arr:
        print(i, end=" ")
    print()


def method1(arr, d):
    temp = array.array('i')
    for i in range(d):
        temp.append(arr[i])
    for i in range(len(arr)-d):
        arr.insert(i, arr.pop(i+d))
    return arr


def method1_ext(arr, d):
    temp = array.array('i')
    for i in range(d):
        temp.append(arr[i])
    for i in range(d, len(arr)):
        arr[i-d] = arr[i]
    for i in range(d):
        arr[len(arr)-d+i] = temp[i]
    return arr


myarr = array.array('i', [1, 2, 3, 4, 5, 6])
show(myarr, "Orignal")
n = int(input("rotation d? "))
show(method1(myarr, n), "Method 1")
myarr = array.array('i', [1, 2, 3, 4, 5, 6])
show(method1_ext(myarr, n), "Method 1 ext")

'''
Method 2: Rotate one by one.
    -> loop for d times
    -> for each time rotate array by one time.
'''


def method2(arr, d):
    for _ in range(d):
        temp = arr[0]
        for i in range(len(arr)-1):
            arr[i] = arr[i+1]
        arr[len(arr)-1] = temp
    return arr


myarr = array.array('i', [1, 2, 3, 4, 5, 6])
show(method2(myarr, n), "Method 2")

'''
Method 3: Juggling algorithm extension of method 2.
    -> rotate gcd(n, d) times at one time instead of only one rotation
    -> make temp array of g size.
    -> rotate one gcd size array at one time, till all gets rotated.
    -> place temp at the end.
'''


def method3(arr, d):
    g = gcd(len(arr), d)
    for i in range(g):
        temp = arr[i]
        j = i
        while True:
            k = j + d
            if k >= len(arr):
                k = k - len(arr)
            if k == i:
                break
            arr[j] = arr[k]
            j = k
        arr[j] = temp
    return arr


myarr = array.array('i', [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12])
show(method3(myarr, n), "Method 3")


'''
Method 4: Reverse 2 times to get the original one.
    -> reverse d items, reverse remaining items.
    -> reverse the complete list.
'''


def reverse(arr, start, stop):
    while start < stop:
        arr[start], arr[stop] = arr[stop], arr[start]
        start += 1
        stop -= 1
    return arr


def method4(arr, d):
    n = len(arr)
    reverse(arr, 0, d-1)
    reverse(arr, d, n-1)
    reverse(arr, 0, n-1)
    return arr


myarr = array.array('i', [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12])
show(method4(myarr, n), "Method 4")
