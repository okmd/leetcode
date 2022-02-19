
// Given arrival and departure time of each train time.
// job is to find the minimum no of platform required at maximum in whole day.
// IDEA: sort the arrival time so that platform can be assigned as the trains comes.
// Sort the departure time so that when a train leaves the platform becomes empty
// it does not matter which one leaves, only thing matters is a train leaves the station.
int findPlatform(int arr[], int dep[], int n) {
    // sort the arrival and departure in ascending order
    sort(arr, arr + n);
    sort(dep, dep + n);
    // take a platform for first train
    int curr_pltform_needed = 1;
    int min_platform_needed = 1;
    int i = 1, j = 0;  // arrival and departure
    // if other tain comes and which is less than the sorted dep time i.e new platform will be required.
    while (i < n and j < n) {
        if (arr[i] <= dep[j]) {
            curr_pltform_needed++;
            i++;
        } else {
            curr_pltform_needed--;
            j++;
        }
        min_platform_needed = max(min_platform_needed, curr_pltform_needed);
    }
    return min_platform_needed;
}