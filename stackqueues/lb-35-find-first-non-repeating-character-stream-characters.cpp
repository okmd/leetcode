#include <iostream>
#include <string>
#include <vector>
using namespace std;

// LC
int firstUniqChar(string s) {
    // return index of fist non-repeating char
    // if occured for the first the first time then it is non-repeating
    // if again-occured then it is repeated, dont cosider it.
    // find use queue to find first
    int repreating[26] = {0};
    int non_repeating[26] = {0};
    for (int i = 0; i < s.length(); i++) {
        int index = s[i] - 'a';
        if (repreating[index]) {
            // if already repeated this char do nothing
            continue;
        } else if (non_repeating[index]) {
            // i.e occured one time earlier now coming for second time.
            // so repeating and no-longer non-repeating
            non_repeating[index] = 0;
            repreating[index] = 1;
        } else {
            // coming for the fist time hence
            // non-repeating
            non_repeating[index] = 1;
        }
    }
    // loop through the elmenets, if found first non-repeating then return
    for (int i = 0; i < s.length(); i++) {
        if (non_repeating[s[i] - 'a']) return i;
    }

    return -1;
}
// GFG
string FirstNonRepeating(string s) {
    string ans, temp;
    int frequency[26] = {0};
    int n = s.length();
    bool first;
    for (int i = 0; i < n; i++) {
        int index = s[i] - 'a';
        if (!frequency[index]) {
            // first time occurance
            temp.push_back(s[i]);
        }
        // increase freq as this element has occured
        frequency[index]++;
        first = false;
        // find if fist non-repeating exits for this element or not
        for (int j = 0; j < temp.length(); j++) {
            // occured only 1 time not less or more
            // and this would be first non-repeating char
            if (frequency[temp[j] - 'a'] == 1) {
                first = true;
                ans.push_back(temp[j]);
                break;
            }
        }
        if (!first) ans.push_back('#');
    }
    return ans;
}