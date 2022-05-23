int search(int arr[], int n, int x, int k) {
    int i = 0;
    while (i < n) {
        if (arr[i] == x) return i;
        i += max(1, abs(arr[i] - x) / k);
        // in worst case 2,4,6,8,10,... k=2, x=6
        // if current difference is k then move 1 step
        // if 2k then move 2 step; ..
        // but not worst case then more step will be required to find x
        // as 2,3,4,5,6,7,8,9,10..k=2, x=6
        // in both cases move atleast diff/k steps.
        // but overall atleast 1 step should move forward.
    }
    return -1;
}