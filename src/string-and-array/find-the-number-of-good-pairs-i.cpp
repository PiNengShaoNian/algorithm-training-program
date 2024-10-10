class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int, int> count1;
        unordered_map<int, int> count2;
        int max1 = nums1[0];
        for (int num : nums1) {
            count1[num]++;
            max1 = max(max1, num);
        }

        for (int num : nums2) {
            count2[num]++;
        }

        int res = 0;
        for (auto &pair : count2) {
            int a = pair.first;
            int cnt = pair.second;
            for (int p = a * k; p <= max1; p += a * k) {
                if (count1.count(p)) {
                    res += cnt * count1[p];
                }
            }
        }
        return res;
    }
};