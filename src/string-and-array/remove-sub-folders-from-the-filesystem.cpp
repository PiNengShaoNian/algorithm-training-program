class Solution {
 public:
  vector<string> removeSubfolders(vector<string>& folder) {
    sort(folder.begin(), folder.end());
    vector<string> ans = {folder[0]};
    for (int i = 1; i < folder.size(); i++) {
      int pre = ans.end()[-1].size();
      if (!(pre < folder[i].size() &&
            ans.end()[-1] == folder[i].substr(0, pre) &&
            folder[i][pre] == '/')) {
        ans.push_back(folder[i]);
      }
    }
    return ans;
  }
};