class RandomizedSet {
 public:
  unordered_map<int, int> valToIdx;
  vector<int> vals;
  RandomizedSet() { srand((unsigned)time(NULL)); }

  bool insert(int val) {
    if (valToIdx.count(val)) {
      return false;
    }

    valToIdx[val] = vals.size();
    vals.push_back(val);
    return true;
  }

  bool remove(int val) {
    if (valToIdx.count(val) == 0) {
      return false;
    }

    int idx = valToIdx[val];
    int temp = vals.back();
    vals[idx] = temp;
    valToIdx[temp] = idx;
    vals.pop_back();
    valToIdx.erase(val);
    return true;
  }

  int getRandom() {
    int randomIndex = rand() % vals.size();
    return vals[randomIndex];
  }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */