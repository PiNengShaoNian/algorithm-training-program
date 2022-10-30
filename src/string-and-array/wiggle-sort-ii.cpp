class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        int x = (n + 1) / 2;

        for(int i = 0, k = x - 1, j = n - 1; i < n; i += 2, --j, --k) {
            nums[i] = arr[k];

            if(i + 1 < n) {
                nums[i + 1] = arr[j];
            }
        }
    }
};