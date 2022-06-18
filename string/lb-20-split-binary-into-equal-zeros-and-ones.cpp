#include<iostream>
using namespace std;
int split(string s) {
    int zeros = 0, ones = 0, twos = 0, ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') zeros++;
        else ones++;
        if (zeros == ones) ans++;
    }
    // if anyone have move count then string is not balance hence cant be split
    return (zeros == ones) ? ans : -1;
}
int main() {
    string s;
    cin >> s;
    cout << split(s);
    return 0;
}