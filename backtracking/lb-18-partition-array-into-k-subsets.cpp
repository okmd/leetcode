#include<iostream>
#include<vector>
using namespace std;
bool helper(int a[], int n, int k, int curr_sum, int count, vector<bool>& visited, int ssm) {
    if (count == k - 1) return true;
    if (curr_sum > ssm) return false;
    // create a new subset;
    if (curr_sum == ssm and helper(a, n, k, 0, count + 1, visited, ssm)) return true; // as true is found no need to check further;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            //add to current subset
            if (helper(a, n, k, curr_sum + a[i], count, visited, ssm)) return true;
            visited[i] = false;
        }
    }
    return false;
}
bool isKPartitionPossible(int a[], int n, int k) {
    int sm = 0;
    for (int i = 0; i < n; i++) sm += a[i];
    if (sm % k) return false;
    int ssm = sm / k; // k box each box has ssm;
    // it is possible to make ssm k times;
    vector<bool> visited(n, false);
    return helper(a, n, k, 0, 0, visited, ssm);
}
int main() {
    int arr[] = {2,1,4,5,6};//{ 4, 3, 2, 3, 5, 2, 1 };
    int k = 3;//5;
    int n = 5;//7;
    cout << isKPartitionPossible(arr, n, k) << endl;
    return 0;
}