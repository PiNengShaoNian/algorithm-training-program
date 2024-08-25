class Solution {
 public:
  int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                          vector<int>& worker) {
    int n = difficulty.size();
    struct Job {
      int diff;
      int profit;
    };
    vector<Job> jobs(n);
    for (int i = 0; i < n; i++) {
      jobs[i].diff = difficulty[i];
      jobs[i].profit = profit[i];
    }
    sort(jobs.begin(), jobs.end(),
         [](const Job& a, const Job& b) -> bool { return a.diff < b.diff; });
    sort(worker.begin(), worker.end());

    int best = 0, ans = 0, i = 0;
    for (int skill : worker) {
      while (i < n && skill >= jobs[i].diff) {
        best = max(jobs[i].profit, best);
        i++;
      }

      ans += best;
    }
    return ans;
  }
};