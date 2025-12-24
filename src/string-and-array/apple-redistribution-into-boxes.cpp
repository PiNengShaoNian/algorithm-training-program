class Solution {
 public:
  int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
    sort(capacity.begin(), capacity.end(), [](int a, int b) { return a > b; });

    int sum = accumulate(apple.begin(), apple.end(), 0);
    int c = 0;
    for (int i = 0; i < capacity.size(); i++) {
      c += capacity[i];
      if (c >= sum) {
        return i + 1;
      }
    }
    return -1;
  }
};