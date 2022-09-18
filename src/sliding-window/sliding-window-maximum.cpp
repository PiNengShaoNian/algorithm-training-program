//单调队列解法
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        vector<int> ans;
        for(int i = 0; i < n; ++i) {
            if(q.size() && i - q.front() >= k) q.pop_front();

            while(q.size() && nums[q.back()] <= nums[i]) q.pop_back();

            q.push_back(i);

            if(i - k + 1 >= 0) {
                ans.push_back(nums[q.front()]);
            }
        }

        return ans;
    }
};