#include<iostream>
using namespace std;

int main() {
    int t, j = 0;
    cin >> t;
    while (++j <= t) {
        int n, k, b, t;
        cin >> n >> k >> b >> t; // chicken, atleast k to reach barn, barn pos, time to reach
        int x[n], v[n];
        for (int i = 0; i < n; i++) cin >> x[i]; // position
        for (int i = 0; i < n; i++) cin >> v[i]; // speed
        int count = 0, swaps = 0, not_possible = 0;
        // 
        for (int i = n - 1; i >= 0 and count < k; i--) {
            int dis_needed = b - x[i]; // curr chick dis needed to reach barn
            int dis_possible = v[i] * t; // dis reached by curr chick in time t;
            if (dis_needed > dis_possible) not_possible++;
            else {
                count++; // curr chick can reach barn in time t;
                swaps += (not_possible > 0) ? not_possible : 0;
                // if there is any slower chick after faster chick then swap
            }
        }
        cout << "Case #" << j << ": " << ((count >= k) ? to_string(swaps) : "IMPOSSIBLE") << endl;
    }
    return 0;
}