// n/2
int majorityElement(int a[], int size) {
    // pair each element
    // if after pairing non-unique element if still some elements left then it can be majority
    int cnt = 0;
    int maj = 0;
    for (int i = 0; i < size; i++) {
        // if all elements formed pairs then there is no majority: 1,2,1,2
        if (cnt == 0)
            maj = a[i];
        // if current element is same as mojority then increase count else dec
        cnt += (maj == a[i]) ? 1 : -1;
    }
    // verify count of majority
    int c = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] == maj) c++;
    }
    // if occures more than n/2 time
    return (c > size / 2) ? maj : -1;
}

// n/3
vector<int> majorityElement(vector<int>& arr) {
    vector<int> ans;
    // n%3 = 0, 1, 2 i.e at max 2 majority ele will exits
    // 1,2,3|1,2,3|1,2,3|(1,2)
    // 9%3 = 0, each of the count(1,2,3) =3 equal to 3 not more than 3
    // 10%3 = 1, count(1) = 4>3
    // 11%3 = 2, count(1,2) = 4>3
    // but majority element candidate has to be verified
    // e.g 1,2,3|1,2,3|1,2,3|(4,5) -> no majority
    int m1 = -1, m2 = -1;
    int c1 = 0, c2 = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == m1)
            c1++;
        else if (arr[i] == m2)
            c2++;
        else if (c1 == 0) {
            m1 = arr[i];
            c1 = 1;
        } else if (c2 == 0) {
            m2 = arr[i];
            c2 = 1;
        } else {
            c1--;
            c2--;
        }
    }
    // verify
    int n = arr.size();
    c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == m1)
            c1++;
        else if (arr[i] == m2)
            c2++;
    }
    if (c1 > n / 3) ans.push_back(m1);
    if (c2 > n / 3) ans.push_back(m2);
    return ans;
}