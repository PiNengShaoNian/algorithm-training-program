class Solution {
    public:
        int countLargestGroup(int n) {
            unordered_map<int, int> cnt;
            int maxValue = 0;
            for (int i = 1; i <= n; i++) {
                int key = 0, i0 = i;
                while (i0) {
                    key += i0 % 10;
                    i0 /= 10;
                }
                cnt[key]++;
                maxValue = max(cnt[key], maxValue);
            }
    
            int count = 0;
            for (auto &pair : cnt) {
                if (pair.second == maxValue) {
                    count++;
                }
            }
            return count;
        }
    };