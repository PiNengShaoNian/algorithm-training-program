class FindSumPairs {
 private:
  unordered_map<int, int> cnt;
  vector<int> nums1;
  vector<int> nums2;

 public:
  FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
    this->nums1 = nums1;
    this->nums2 = nums2;
    for (int num : nums2) {
      cnt[num]++;
    }
  }

  void add(int index, int val) {
    int old_val = nums2[index];
    int new_val = nums2[index] + val;
    nums2[index] = new_val;
    cnt[old_val]--;
    cnt[new_val]++;
  }

  int count(int tot) {
    int ans = 0;
    for (int num : nums1) {
      if (cnt.count(tot - num)) {
        ans += cnt[tot - num];
      }
    }
    return ans;
  }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */