class NumberContainers {
  unordered_map<int, int> indexToNumber;
  unordered_map<int, set<int>> numberToIndexes;

 public:
  NumberContainers() {}

  void change(int index, int number) {
    if (indexToNumber.count(index)) {
      int prevNumber = indexToNumber[index];
      numberToIndexes[prevNumber].erase(index);
      if (numberToIndexes[prevNumber].size() == 0) {
        numberToIndexes.erase(prevNumber);
      }
    }
    indexToNumber[index] = number;
    numberToIndexes[number].insert(index);
  }

  int find(int number) {
    if (!numberToIndexes.count(number)) {
      return -1;
    }
    return *numberToIndexes[number].begin();
  }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */