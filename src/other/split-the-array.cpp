class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        int cnt[101] = {0};
        for (int num : nums) {
            cnt[num]++;
            if (cnt[num] > 2) {
                return false;
            }
        }
        return true;
    }
};