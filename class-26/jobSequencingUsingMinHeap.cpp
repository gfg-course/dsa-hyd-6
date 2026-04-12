#include<bits/stdc++.h>
using namespace std;

class Job {
public:
    int id;
    int deadline;
    int profit;

    Job(int id, int deadline, int profit) {
        this->id = id;
        this->deadline = deadline;
        this->profit = profit;
    }
};

bool deadlineComp(Job* &a, Job* &b) {

    if (a->deadline == b->deadline) {
        return a->profit > b->profit;
    }

    return a->deadline < b->deadline;
}

// TC: O(n*log(n))
// AS: O(n)
pair<int, int> getMaxProfit(vector<Job*> jobs) {
    int n = jobs.size();
    
    sort(jobs.begin(), jobs.end(), deadlineComp);
    priority_queue<int, vector<int>, greater<int>> profits; // min-heap of profits.

    int jobsDone = 0, maxProfit = 0;

    for (int i = 0; i < n; i++) {
        if (jobs[i]->deadline > jobsDone) {
            jobsDone++;
            maxProfit += jobs[i]->profit;
            profits.push(jobs[i]->profit);
        } else {
            if (jobs[i]->profit > profits.top()) {
                maxProfit += jobs[i]->profit - profits.top();
                profits.pop();
                profits.push(jobs[i]->profit);
            }
        }
    }

    return {jobsDone, maxProfit};
}

int main() {

    pair<int, int> res1 = getMaxProfit({
        new Job(1, 2, 100),
        new Job(2, 1, 19),
        new Job(3, 2, 27),
        new Job(4, 1, 25),
        new Job(5, 1, 15)
    });

    cout << res1.first << " " << res1.second;
}
