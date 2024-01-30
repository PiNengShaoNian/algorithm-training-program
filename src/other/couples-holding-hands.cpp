class Solution {
 public:
  int minSwapsCouples(vector<int>& row) {
    int len = row.size();
    int cnt = 0;
    for (int i = 0; i < len; i++) {
      row[i] = row[i] / 2;
    }

    for (int i = 0; i < len; i += 2) {
      if (row[i] != row[i + 1]) {
        for (int j = i + 2; j < len; j++) {
          if (row[i] == row[j]) {
            swap(row[i + 1], row[j]);
            cnt++;
            break;
          }
        }
      }
    }
    return cnt;
  }
};