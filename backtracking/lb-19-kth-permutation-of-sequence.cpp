#include<iostream>
#include<vector>
using namespace std;
// Brute force is to generate all possible permutations; sort then find value at k-1th element;
string getPermutation(int n, int k) {
    vector<int> nums;
    string ans;
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        nums.push_back(i); // create set for 1,2,3....n
        fact *= i; // n!
    }
    k--; // 0-based indexing
    while (nums.size()) {
        fact /= nums.size(); // reduce factorial as one element is reuced;
        int loc = k / fact;
        ans += to_string(nums[loc]); // 1|{234} -> 3!=6 same for 2,3,4
        nums.erase(nums.begin() + loc); // erase the picked element
        k %= fact; // k lies in this group of (n-1)! so find new index of k
    }
    return ans;
}
int main() {
    int n = 7;
    int k = 1000;
    cout << getPermutation(n, k) << endl;
    return 0;
}