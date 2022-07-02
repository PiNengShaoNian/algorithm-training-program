class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> vec;

        int n = nums.size();

        for(int i = 0; i < n; ++i) {
            int p = lower_bound(vec.begin(), vec.end(), nums[i]) - vec.begin();

            if(p < (int)vec.size()) {
                vec[p] = nums[i];
            }
            else {
                vec.push_back(nums[i]);
            }
        }

        return (int)vec.size();
    }
};