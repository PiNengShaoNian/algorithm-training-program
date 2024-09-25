class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_map<char, unordered_set<string>> names;
        for (string& idea : ideas) {
            names[idea[0]].insert(idea.substr(1, idea.size() - 1));
        }

        auto get_intersect_size = [](const unordered_set<string> &a, const unordered_set<string> &b) -> int {
            int ans = 0;
            for (const string &suffix1 : a) {
                if (b.count(suffix1)) {
                    ans++;
                }
            }
            return ans;
        };

        long long ans = 0;
        for (auto &&[pre_a, set_a] : names) {
            for (auto &&[pre_b, set_b] : names) {
                if (pre_a == pre_b) {
                    continue;
                }
                int intersect = get_intersect_size(set_a, set_b);
                ans += (set_a.size() - intersect) * (set_b.size() - intersect);
            }
        }

        return ans;
    }
};