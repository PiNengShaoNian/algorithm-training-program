class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n = votes.size();
        unordered_map<int, vector<int>> ranking;
        for (char vid : votes[0]) {
            ranking[vid].resize(votes[0].size());
        }

        for (const string &vote : votes) {
            for (int i = 0; i < vote.size(); i++) {
                ranking[vote[i]][i]++;
            }
        }

        using PCV = pair<int, vector<int>>;
        vector<PCV> result(ranking.begin(), ranking.end());
        sort(result.begin(), result.end(), [](const PCV &l, const PCV &r) {
            return l.second > r.second || (l.second == r.second && l.first < r.first);
        });
        string ans;
        for (auto &[vid, rank] : result) {
            ans += vid;
        }
        return ans;
    }
};