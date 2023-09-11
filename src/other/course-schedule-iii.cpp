class Solution {
 public:
  int scheduleCourse(vector<vector<int>>& courses) {
    sort(courses.begin(), courses.end(),
         [](vector<int>& a, vector<int>& b) -> bool { return a[1] < b[1]; });
    priority_queue<int> pq;

    int curr = 0;
    for (vector<int>& c : courses) {
      int ti = c[0];
      int di = c[1];

      if (curr + ti <= di) {
        pq.push(ti);
        curr += ti;
      } else if (pq.size() && pq.top() > ti) {
        curr -= pq.top() - ti;
        pq.pop();
        pq.push(ti);
      }
    }
    return pq.size();
  }
};