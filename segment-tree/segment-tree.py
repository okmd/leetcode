st = []


def buildSegTree(st_idx, arr, s, e):
    if s > e:
        return
    # basecase
    # leaf
    if s == e:
        st[st_idx] = arr[s]
        return
    # internal node, partition
    mid = s + (e-s)//2
    buildSegTree(2*st_idx, arr, s, mid)
    buildSegTree(2*st_idx+1, arr, mid+1, e)
    st[st_idx] = st[2*st_idx] + st[2*st_idx+1]


def q(qs, qe, st_idx, s, e):
    # no overlap
    if qs > e or qe < s:
        return 0
    # total overlap
    if s >= qs and e <= qe:
        return st[st_idx]
    # partial overlap
    mid = s + (e-s)//2
    ls = q(qs, qe, 2*st_idx, s, mid)
    rt = q(qs, qe, 2*st_idx+1, mid+1, e)
    return ls + rt


def update(st_idx, s, e, pos, val):
    # no overlap
    if s > pos or e < pos:
        return 0
    # total overlap
    if s == e:
        st[st_idx] = val
        return
    # partial overlap
    mid = s + (e-s)//2
    update(2*st_idx, s, mid, pos, val)
    update(2*st_idx+1, mid+1, e, pos, val)
    st[st_idx] = st[2*st_idx] + st[2*st_idx+1]


def main():
    n = 6
    global st
    arr = [1, 3, 2, -2, 4, 5]
    st = [0]*4*(n+1)
    st_idx = 1
    start = 0
    end = n-1
    buildSegTree(st_idx, arr, start, end)
    print(st)
    print(f"Sum 2-4:{q(2,4, st_idx, start, end)} ")
    print(f"Sum 1-4:{q(1,4, st_idx, start, end)} ")
    print(f"Sum 3-3:{q(3,3, st_idx, start, end)} ")
    # arr[2] = 100
    update(st_idx, start, end, 2, 100)
    print(st)
    print(f"Sum 2-4:{q(2,4, st_idx, start, end)} ")
    print(f"Sum 1-4:{q(1,4, st_idx, start, end)} ")
    print(f"Sum 3-3:{q(3,3, st_idx, start, end)} ")


main()
