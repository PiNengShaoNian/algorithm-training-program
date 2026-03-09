class Solution {
 public:
  string findDifferentBinaryString(vector<string>& nums) {
    int n = nums.size();
    unordered_set<int> vals;
    for (const string& num : nums) {
      vals.insert(stoi(num, nullptr, 2));
    }

    int val = 0;
    while (vals.count(val)) {
      val++;
    }
    return bitset<16>(val).to_string().substr(16 - n, 16);
  }
};