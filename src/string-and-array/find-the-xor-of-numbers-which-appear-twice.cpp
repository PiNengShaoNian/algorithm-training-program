class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int res = 0;
        long long countSet = 0;
        for (int num : nums) {
            if ((1L << num) & countSet) {
                res ^= num;
            } else {
                countSet |= (1L << num);
            }
        }
        return res;
    }
};