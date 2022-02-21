// Given N number of Platforms
// M number of trains
// Print the maximum number of trains to which stoppage can be provided.
// when ever you are goining to take m+1th platform terminate and give
// ans as current no of trains that has been passed throung the platform
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Item {
   public:
    int arrival;
    int departure;
    int platform;

    Item(int a, int d, int p) {
        arrival = a;
        departure = d;
        platform = p;
    }
};

int max_stoppage_for_trains(int arr[], int dep[], int plt[], int n) {
    // n = number of trains
    // m = number of platforms
    // combine and sort based on the departure time
    // keep assigning the trains to the platform based on dep.time
    vector<Item *> comb;
    for (int i = 0; i < n; i++) {
        comb.push_back(new Item(arr[i], dep[i], plt[i]));
    }
    sort(comb.begin(), comb.end(), [](Item *a, Item *b) {
        return a->departure < b->departure;
    });

    int i = 1;
    int max_train = 1;
    int dept_temp[n];
    for (int i = 0; i < n; i++) dept_temp[i] = -1;

    dept_temp[comb[0]->platform - 1] = comb[0]->departure;

    while (i < n) {
        int curr_plt = comb[i]->platform - 1;
        if (dept_temp[curr_plt] == -1 or dept_temp[curr_plt] <= comb[i]->arrival) {
            max_train++;
            dept_temp[curr_plt] = comb[i]->departure;
        }
        i++;
    }
    return max_train;
}

int main() {
    int arr[] = {1000, 1010, 1025, 1130, 1130};  //{1000, 1010, 1000, 1030, 1200, 900};   //
    int dep[] = {1030, 1020, 1040, 1145, 1140};  //{1030, 1030, 1020, 1230, 1230, 1005};  //
    int plt[] = {1, 1, 1, 2, 2};                 //{1, 1, 2, 2, 3, 1};                    //
    int n = sizeof(arr) / sizeof(int);
    cout << max_stoppage_for_trains(arr, dep, plt, n);
    return 0;
}