class Solution {
 public:
  using MinPQ = priority_queue<int, vector<int>, greater<int>>;
  bool isPossible(vector<int> &nums) {
    unordered_map<int, MinPQ *> seqLastNumToSeqLen;

    for (int num : nums) {
      if (seqLastNumToSeqLen.find(num) == seqLastNumToSeqLen.end()) {
        seqLastNumToSeqLen[num] = new MinPQ();
      }

      auto it = seqLastNumToSeqLen.find(num - 1);
      if (it == seqLastNumToSeqLen.end()) {
        seqLastNumToSeqLen[num]->push(1);
      } else {
        MinPQ *pq = it->second;
        int minLen = pq->top();
        pq->pop();

        if (pq->empty()) {
          seqLastNumToSeqLen.erase(num - 1);
        }

        MinPQ *xPq = seqLastNumToSeqLen[num];
        xPq->push(minLen + 1);
      }
    }
    cout << seqLastNumToSeqLen.size() << endl;

    for (auto it : seqLastNumToSeqLen) {
      if (it.second->top() < 3) {
        return false;
      }
    }

    return true;
  }
};