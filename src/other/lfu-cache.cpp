class LFUNode {
 public:
  int freq;
  int key;
  int val;
  LFUNode(int _freq, int _key, int _val) : freq(_freq), key(_key), val(_val) {}
};

class LFUCache {
 public:
  map<int, list<LFUNode>> freqToNodeList;
  unordered_map<int, list<LFUNode>::iterator> keyToNode;
  int capacity;
  int minFreq;
  LFUCache(int _capacity) {
    capacity = _capacity;
    minFreq = 0;
  }

  int get(int key) {
    if (capacity == 0) {
      return -1;
    }
    auto it = keyToNode.find(key);
    if (it == keyToNode.end()) {
      return -1;
    }
    list<LFUNode>::iterator node = it->second;
    int val = node->val, freq = node->freq;
    freqToNodeList[freq].erase(node);
    if (freqToNodeList[freq].size() == 0) {
      freqToNodeList.erase(freq);
      if (minFreq == freq) {
        minFreq = freq + 1;
      }
    }

    freqToNodeList[freq + 1].push_front(LFUNode(freq + 1, key, val));
    keyToNode[key] = freqToNodeList[freq + 1].begin();

    return val;
  }

  void put(int key, int value) {
    if (capacity == 0) {
      return;
    }
    auto it = keyToNode.find(key);
    if (it == keyToNode.end()) {
      if (keyToNode.size() == capacity) {
        auto it2 = freqToNodeList[minFreq].back();
        keyToNode.erase(it2.key);
        freqToNodeList[minFreq].pop_back();
        if (freqToNodeList[minFreq].size() == 0) {
          freqToNodeList.erase(minFreq);
        }
      }
      freqToNodeList[1].push_front(LFUNode(1, key, value));
      keyToNode[key] = freqToNodeList[1].begin();
      minFreq = 1;
    } else {
      list<LFUNode>::iterator node = it->second;
      int freq = node->freq;
      freqToNodeList[freq].erase(node);
      if (freqToNodeList[freq].size() == 0) {
        freqToNodeList.erase(freq);
        if (minFreq == freq) {
          minFreq = freq + 1;
        }
      }
      freqToNodeList[freq + 1].push_front(LFUNode(freq + 1, key, value));
      keyToNode[key] = freqToNodeList[freq + 1].begin();
    }
  }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */