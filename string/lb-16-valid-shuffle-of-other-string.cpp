// given s1=abc
// s2=cde
// res = acbcde: oder should be maintained
#include<iostream>
using namespace std;
bool is_suffled(string s1, string s2, string res) {
    int n1 = s1.size();
    int n2 = s2.size();
    int n3 = res.size();
    if (n1 + n2 != n3) return false;
    int i1 = 0, i2 = 0, i3 = 0;
    int found = 0;
    while (i1 < n1 and i2 < n2) {
        if (res[i3] == s1[i1]) i1++;
        else if (res[i3] == s2[i2]) i2++;
        else return false;
        i3++;
    }
    return true;
}
int main() {
    string s1 = "xyi";
    string s2 = "1z";
    string s3 = "x1yz";
    cout <<(is_suffled(s1, s2, s3)?"YES":"NO");
    return 0;
}