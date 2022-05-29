// calculate left min
// can right min of rach bar
// area = (right[i]-left[i]+1)*ht[i] using monotomically increasing stack

int max_histogram_area(vector<int>& arr) {
    vector<int> left(arr.size(), 0);
    int i = 0, width;
    stack<int> st; // MIS
    int max_area = INT_MIN;
    // each bar is assumed to be included fully.
    while (i <= arr.size()) {
        while (st.size() and (i == arr.size() or arr[st.top()] >= arr[i])) {
            // found right lower element of top of stack, ignoring left lower due to MIS
            int height = arr[st.top()]; // ht of top of stack that is going to be included fully
            st.pop();
            // if there is no element in stack then then all elements till i are included as 0 based index
            // ele till top of stack
            width = (st.size()) ? i - st.top() - 1 : i;
            max_area = max(max_area, width * height);
        }
        st.push(i++);
    }
    return max_area;
}
int maximalRectangle(vector<vector<int>>& matrix) {
    int mx_area = INT_MIN;
    int area;
    vector<int> temp(matrix[0].size(), 0);
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < temp.size(); j++) {
            // add one row above other, if lower row have 0 then histogram will become 0
            temp[j] = (matrix[i][j]) ? temp[j] + 1 : 0;
        }
        area = max_histogram_area(temp);
        mx_area = max(mx_area, area);
    }
    return mx_area;
}

class Solution {
   public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        vector<vector<int>> v;
        for (int i = 0; i < n; i++) {
            vector<int> k;
            for (int j = 0; j < m; j++) {
                k.push_back(M[i][j]);
            }
            v.push_back(k);
        }
        return maximalRectangle(v);
    }
};