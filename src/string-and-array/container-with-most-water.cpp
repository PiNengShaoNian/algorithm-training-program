class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;

        int l = 0;
        int r = height.size() - 1;

        while(l < r) {
            int minH = min(height[l], height[r]);
            ans = max(ans, minH * (r - l));

            while (height[l] <= minH && l < r) {
                l++;
            }

            while (height[r] <= minH && l < r) {
                r--;
            }
        }

        return ans;
    }
};