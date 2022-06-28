class Solution {
public:
    vector<vector<int> > ans;
    vector<int> temp;
    void helper(vector<int>& A, int sm, int index) {
        if (sm == 0) {
            ans.push_back(temp);
            return;
        }
        while (index < A.size() and sm >= A[index]) {
            temp.push_back(A[index]);
            helper(A, sm - A[index], index);
            temp.pop_back();
            index++;
        }
    }
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int>& A, int B) {
        sort(A.begin(), A.end());
        A.erase(unique(A.begin(), A.end()), A.end());// remove from array itself
        // Erase remove the elements in range while clear remove everything {}
        // Unique return new end and vector contains only unique elements;
        helper(A, B, 0);
        return ans;
    }
};