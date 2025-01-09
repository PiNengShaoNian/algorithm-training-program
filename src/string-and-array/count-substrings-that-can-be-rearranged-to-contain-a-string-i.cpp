class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        vector<int> diff(26);
        for (char c : word2) {
            diff[c - 'a']--;
        }

        int cnt = count_if(diff.begin(), diff.end(), [](int c) { return c < 0; });
        auto update = [&](int add, int pos) {
            diff[pos] += add;
            if (add == 1 && diff[pos] == 0) {
                cnt--;
            } else if (add == -1 && diff[pos] == -1) {
                cnt++;
            }
        };

        long long ans = 0;
        for (int l = 0, r = 0; l < word1.size(); l++) {
            while (r < word1.size() && cnt > 0) {
                update(1, word1[r] - 'a');
                r++;
            }

            if (cnt == 0) {
                ans += word1.size() - r + 1;
            }
            update(-1, word1[l] - 'a');
        }
        return ans;
    }
};