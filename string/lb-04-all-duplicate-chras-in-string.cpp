// method 1: map for string freq of each char
// same can be done by storing freq of 26 chars in array.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void duplicates(string S) {
    int count[26] = {0};
    for (auto s : S) {
        count[s - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] == 0) continue;
        char w = (i + 'a');
        cout << w << " : " << count[i] << " ";
    }
}
int main() {
    string s = "helloe";
    duplicates(s);
    return 0;
}