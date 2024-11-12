class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int cnt[] = {0, 0};
        int ans = 0;

        int left = 0;
        int n = s.size();
        for (int right = 0; right < n; right++) {
            cnt[s[right] - '0']++;
            while (cnt[0] > k && cnt[1] > k) {
                cnt[s[left] - '0']--;
                left++;
            }
            ans += right - left + 1;
        }
        return ans;
    }
};