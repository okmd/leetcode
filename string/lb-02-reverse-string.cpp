void reverseString(vector<char>& s) {
    int n = s.size();
    int i = 0, j = n - 1;
    while (i < j) {
        char x = s[i];
        s[i] = s[j];
        s[j] = x;
        i++;
        j--;
    }
}