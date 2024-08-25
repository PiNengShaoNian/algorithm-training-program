class Solution {
 public:
  vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom,
                              vector<int>& moveTo) {
    vector<int> ans;
    unordered_set<int> numSet;
    for (int num : nums) {
      numSet.insert(num);
    }

    for (int i = 0; i < moveFrom.size(); i++) {
      numSet.erase(moveFrom[i]);
      numSet.insert(moveTo[i]);
    }

    for (const int num : numSet) {
      ans.push_back(num);
    }
    sort(ans.begin(), ans.end());
    return ans;
  }
};