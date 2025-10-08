class Solution {
 public:
  vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                              long long success) {
    sort(potions.begin(), potions.end());
    vector<int> ans;
    for (int spell : spells) {
      long long t = (success + spell - 1) / spell;
      ans.push_back(potions.end() -
                    lower_bound(potions.begin(), potions.end(), t));
    }
    return ans;
  }
};