class Solution {
 public:
  vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                            int firstPerson) {
    vector<int> fa(n);
    for (int i = 0; i < n; i++) {
      fa[i] = i;
    }

    function<int(int)> find = [&](int x) -> int {
      if (fa[x] == x) {
        return x;
      }

      return fa[x] = find(fa[x]);
    };

    sort(meetings.begin(), meetings.end(),
         [](const vector<int>& a, const vector<int>& b) -> bool {
           return a[2] < b[2];
         });

    fa[find(0)] = find(firstPerson);
    for (int i = 0, j = 0; i < meetings.size();) {
      while (j < meetings.size() && meetings[j][2] == meetings[i][2]) {
        fa[find(meetings[j][0])] = find(meetings[j][1]);
        j++;
      }
      for (int index = i; index < j; index++) {
        if (find(0) != find(meetings[index][0]) &&
            find(0) != find(meetings[index][1])) {
          fa[meetings[index][0]] = meetings[index][0];
          fa[meetings[index][1]] = meetings[index][1];
        }
      }
      i = j;
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (find(i) == find(0)) {
        ans.push_back(i);
      }
    }

    return ans;
  }
};