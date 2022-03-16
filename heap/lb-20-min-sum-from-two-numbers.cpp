// can;t work in large no
class Solution {
   public:
    string solve(int arr[], int n) {
        // idea is to use min heap to create two numbers
        priority_queue<int, vector<int>, greater<int>> heap;
        for (int i = 0; i < n; i++) {
            heap.push(arr[i]);
        }
        // pop 1st least element ans create 1st number;s unit digit
        // pop 2nd least element and create 2nd number;s unit digit
        // repeate the same process till heap becomes empty
        int n1 = 0;
        int n2 = 0;
        while (heap.size()) {
            int min_ele = heap.top();
            n1 = n1 * 10 + min_ele;
            heap.pop();
            if (heap.size()) {
                int min_ele2 = heap.top();
                n2 = n2 * 10 + min_ele2;
                heap.pop();
            }
        }
        // find sum and convert to string
        int sm = n1 + n2;
        return to_string(sm);
    }
};

// for large no
string convert_to_string(vector<int> nums) {
    stringstream result;
    copy(nums.begin(), nums.end(), std::ostream_iterator<int>(result, ""));
    return result.str();
}
class Solution {
   public:
    string solve(int arr[], int n) {
        // idea is to use min heap to create two numbers
        priority_queue<int, vector<int>, greater<int>> heap;
        // don;t insert zeros as they are going to be placed at front
        for (int i = 0; i < n; i++) {
            if (arr[i] != 0)
                heap.push(arr[i]);
        }
        // pop 1st least element ans create 1st number;s unit digit
        // pop 2nd least element and create 2nd number;s unit digit
        // repeate the same process till heap becomes empty
        // create two vector representing numbers
        vector<int> n1, n2;
        while (heap.size()) {
            int min_ele = heap.top();
            n1.push_back(min_ele);
            heap.pop();
            if (heap.size()) {
                int min_ele2 = heap.top();
                n2.push_back(min_ele2);
                heap.pop();
            }
        }
        // find sum and convert to string
        // diff in length is atmost 1
        int sm, carry = 0, unit_digit, i, j;
        vector<int> ans;
        for (i = n1.size() - 1, j = n2.size() - 1; i >= 0 and j >= 0; i--, j--) {
            sm = carry + n1[i] + n2[j];
            carry = sm / 10;
            unit_digit = sm % 10;
            ans.push_back(unit_digit);
        }
        if (i >= 0 or j >= 0) {
            if (i >= 0) {
                sm = carry + n1[i--];
                carry = sm / 10;
            }
            if (i >= 0) {
                sm = carry + n2[j--];
            }
            carry = sm / 10;
            unit_digit = sm % 10;
            ans.push_back(unit_digit);
        }
        // if carry exits then it should also be inserted
        if (carry) {
            ans.push_back(carry);
        }
        string str = convert_to_string(ans);
        reverse(str.begin(), str.end());
        return str;
    }
};