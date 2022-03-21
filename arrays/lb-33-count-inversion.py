def inversionCount(self, arr, n):
    inversions = 0

    def merge(arr, l, m, r):
        nonlocal inversions
        i = l
        j = m+1
        temp = []
        while i <= m and j <= r:
            if arr[i] <= arr[j]:
                temp.append(arr[i])
                i += 1
            else:
                temp.append(arr[j])
                inversions += m-i+1
                j += 1
        while i <= m:
            temp.append(arr[i])
            i += 1
        while j <= r:
            temp.append(arr[j])
            j += 1
        # copy back
        for i in range(l, r+1):
            arr[i] = temp[i-l]

    def merge_sort(arr, l, r):
        if l >= r:
            return
        mid = l+(r-l)//2
        merge_sort(arr, l, mid)
        merge_sort(arr, mid+1, r)
        merge(arr, l, mid, r)

    merge_sort(arr, 0, n-1)

    return inversions
