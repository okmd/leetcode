struct Job {
    int id;      // Job Id
    int dead;    // Deadline of job
    int profit;  // Profit if job is over before or on deadline
};
class Comp {
   public:
    bool operator()(const Job a, const Job b) {
        return a.profit < b.profit;
    }
};
vector<int> JobScheduling(Job arr[], int n) {
    // # sort the array by deadline try to place large deadline first
    // # if more than one job has same deadline then it will only place the job with max profit using heap if slots are available
    sort(arr, arr + n, [](Job a, Job b) {
        return a.dead > b.dead;
    });
    vector<int> profits;
    priority_queue<Job, vector<Job>, Comp> pq;
    for (int i = 0; i < n; i++) {
        int dead = arr[i].dead;
        int free_slots = (i == n - 1) ? dead : dead - arr[i + 1].dead;
        pq.push(arr[i]);
        while (free_slots and pq.size()) {
            int prof = pq.top().profit;
            pq.pop();
            profits.push_back(prof);
            free_slots--;
        }
    }
    return {profits.size(), accumulate(profits.begin(), profits.end(), 0)};
}