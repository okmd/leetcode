int isPalindrome(string S) {
    int n = S.length();
    int i = 0, j = n - 1;
    while (i < j) {
        if (S[i] != S[j]) return false;
        i++;
        j--;
    }
    return true;
}