class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        
        if(n < 2) return 0;

        vector<int> temp(n);
        return countPairs(nums, temp, 0, n - 1);
    }

    int countPairs(vector<int> &nums, vector<int>& temp, int left, int right) {
        if (left == right) return 0;

        int mid = left + (right - left) / 2;

        int leftPairs = countPairs(nums, temp, left, mid);
        int rightPairs = countPairs(nums, temp, mid + 1, right);

        int pairs = mergeAndCount(nums, temp, left, mid, right);

        return leftPairs + rightPairs + pairs;
    }

    int mergeAndCount(vector<int> &nums, vector<int>& temp, int left, int mid, int right) {
        for(int i = left; i <= right; ++i) {
            temp[i] = nums[i];
        }


        int i = left;
        int j = mid + 1;
        int count = 0;
        for(int k = left; k <= right; ++k) {
            if(i == mid + 1) {
                nums[k] = temp[j];
                ++j;
            } 
            else if(j == right + 1) {
                nums[k] = temp[i];
                ++i;
            }
            else if(temp[i] <= temp[j]) {
                nums[k] = temp[i];
                ++i;
            } 
            else {
                nums[k] = temp[j];
                ++j;
                count += (mid -i + 1);
            }
        }

        return count;
    }
};