class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        string str;

        function<void (string &)> dfs = [&](string &s) {
            if (s.size() == n) {
                ans.push_back(s);
                return;
            }

            if (s.empty() || s.back() == '1') {
                s.push_back('0');
                dfs(s);
                s.pop_back();
            }

            s.push_back('1');
            dfs(s);
            s.pop_back();
        };

        dfs(str);

        return ans;
    }
};