// Given required sum S
// Given number of digits whose sum is required sum
// find the digits such that the number is minimum.
// as number will be minimum only if moving from left to right no should be smallest to largest
// or right to left largest to smallest

#include <iostream>
#include <stack>
#include <string>
using namespace std;

string smallestNumber(int S, int D) {
    int i = D - 1;
    stack<int> st;
    while (i >= 0) {
        if (i == 0 and S > 9) return "-1";
        // fill all possible 9 from end,
        if (S > 9) {
            st.push(9);
            S -= 9;
            // if this is fist elements then put what ever the S is and it is guranteed S<=9
        } else if (i == 0) {
            st.push(S);
        } else {
            // put 1 less than required as 1 should me given to first index to make reequired D
            st.push(S - 1);
            // fill all zeros as only zeros will make minimal number
            while (--i > 0) {  // 10, 10 = > 1000000009 instead of anything other combination
                st.push(0);
            }
            // make first element as 1
            st.push(1);
        }
        // decrease for left digit
        i--;
    }
    // pop from stack and create a string
    string s;
    while (!st.empty()) {
        s += to_string(st.top());
        st.pop();
    }
    return s;
}

int main() {
    cout << smallestNumber(9, 2) << endl;   // 18
    cout << smallestNumber(9, 3) << endl;   // 108
    cout << smallestNumber(6, 6) << endl;   // 100005
    cout << smallestNumber(37, 4) << endl;  // -1
    return 0;
}