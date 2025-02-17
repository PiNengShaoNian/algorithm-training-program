class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int cur = arr[0];
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == cur) {
                cnt++;
                if (cnt * 4 > n) {
                    return cur;
                }
            } else {
                cur = arr[i];
                cnt = 1;
            }
        }
        return -1;
    }
};