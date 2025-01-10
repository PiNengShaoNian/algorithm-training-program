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

class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        vector<int> count(26);
        for (char c : word2) {
            count[c - 'a']++;
        }

        int n = word1.size();
        vector<vector<int>> pre_count(n + 1, vector<int>(26, 0));
        for (int i = 1; i <= n; i++) {
            pre_count[i].assign(pre_count[i - 1].begin(), pre_count[i - 1].end());
            pre_count[i][word1[i - 1] - 'a']++;
        }

        auto get = [&](int l) -> int {
            int border = l;
            int r = n;
            int ans = n + 1;
            while (l <= r) {
                int mid = (r - l) / 2 + l;
                int f = true;
                for (int i = 0; i < 26; i++) {
                    if (pre_count[mid][i] - pre_count[border - 1][i] < count[i]) {
                        f = false;
                        break;
                    }
                }

                if (f) {
                    ans = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            return ans;
        };

        long long res = 0;
        for (int i = 1; i <= n; i++) {
            int r = get(i);
            res += n - r + 1;
        }
        return res;
    }
};