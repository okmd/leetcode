// # Circular tour problem.
// # Each node is of (Distance, Petrol)
// # Assume - Always move from, left to right to get min index.
// # For 1 unit distance 1 unit of petrol is required.
// # min possible index from where we can create circular tour i.e start and end points are same.
// # if not possible return -1
// # https://practice.geeksforgeeks.org/problems/circular-tour/1

// Brute force
// start from each location and check if it is possible to complete loop
// without exhausting the petrol

// Optimization: Start from i+1 location if ith location gives -ve fule
// i.e we can not start from any station before ith station
int tour(petrolPump p[], int n) {
    int start = 0;
    int required_fule = 0;
    int extra_fule = 0;
    for (int i = 0; i < n; i++) {
        // when cumulative sum of extra perol
        // in reaching from one station to other
        extra_fule += (p[i].petrol - p[i].distance);
        // do not have sufficent perol
        // so can not start from anylocation before this.
        if (extra_fule < 0) {
            start = i + 1;  // start from next location
            required_fule += extra_fule;
            // now don;t have any extra fule for next starting point
            extra_fule = 0;
        }
    }
    // at the end some extafule left, and
    // if it enough to complete the required journey then true else false;
    // ------[req]Start------[extra]
    return (required_fule + extra_fule >= 0) ? start : -1;
}
