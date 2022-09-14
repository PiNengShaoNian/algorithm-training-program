class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        unordered_map<int,int> count;
        int ans = 0;

        for(int i = 0; i < n; ++i) {
            for(int j = 0;j < n; ++j) {
                ++count[nums1[i] + nums2[j]];
            }
        }

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                auto it = count.find(-(nums3[i] + nums4[j]));
                if(it != count.end())
                {
                    ans += it->second;
                }
            }
        }

        return ans;
    }
};