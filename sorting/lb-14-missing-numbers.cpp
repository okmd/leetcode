int *findTwoElement(int *arr, int n) {
    int *ans = new int[2];
    // add n+1 in each elmenet
    // divide each element by n+1
    // if division is 0 that means nothig is added to that element@index
    // if 1 then added one time or means element exits one time
    // if 2 then element exits two time or duplicate element.
    int m = (n + 1);
    for (int i = 0; i < n; i++) {
        // take mod as array is adding m, again taking % will nullify effect
        arr[arr[i] % m - 1] += m;  // as element 4 will be at @ 4-1=3 in 1-N array, as 1@0,2@1...N@N-1
        // if k comes 2 times then (n+1) is added two times @k-1.
    }
    for (int i = 0; i < n; i++) {
        int div = arr[i] / m;
        if (div == 2) ans[0] = i + 1;
        if (div == 0) ans[1] = i + 1;
    }
    return ans;
}