class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int, int> cnt;
        int ans = 0;

        for (int hour : hours) {
            int h = hour % 24;
            int gap = (24 - h) % 24;

            ans += cnt[gap];
            cnt[h]++;
        }
        return ans;
    }
};