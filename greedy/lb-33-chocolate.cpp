// Given a single Chocolate 2<=n,m<=1000
// m-1 x-cuts and n-1 y-cuts
// cut_cost = line_cost * no_of_parts to be cut
#include <algorithm>
#include <iostream>
using namespace std;

int min_cut_cost(int rows, int cols, int x_cuts[], int y_cuts[]) {
    // cost is sum(multiplications)
    // it will be minimum when we multiply two large number first
    // e.g 4*1 => line cost * single piece; 1*4 = 1 line cost * 4 pieces
    // if we cut 4*2 > 4*1 i.e 2 piece vs 1 piece
    // sort so that minimum can be picked
    sort(x_cuts, x_cuts + rows, greater<int>());
    sort(y_cuts, y_cuts + cols, [](int a, int b) { return a > b; });
    int i = 0, j = 0;
    int x_part = 1;
    int y_part = 1;
    int cost = 0;
    while (i < rows and j < cols) {
        if (x_cuts[i] > y_cuts[j]) {
            cost += x_cuts[i++] * x_part;
            // when cut horizontally = numbers of parts vertically increased
            y_part++;
        } else {
            cost += y_cuts[j++] * y_part;
            // when cut vertically = numbers of parts horizontally increased
            x_part++;
        }
    }
    // either of the array ends then add cost of remaining cuts
    while (i < rows) {
        // x_parts will remain same.
        cost += x_cuts[i++] * x_part;
    }
    while (j < cols) {
        // y_part will same.
        cost += y_cuts[j++] * y_part;
    }
    return cost;
}

int main() {
    int r = 6, c = 4;
    int x[] = {2, 1, 3, 1, 4};
    int y[] = {4, 1, 2};
    cout << min_cut_cost(r - 1, c - 1, x, y);
    return 0;
}