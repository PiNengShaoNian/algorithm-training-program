class Router {
 private:
  int memLimit = 0;
  int length = 0;
  set<tuple<int, int, int>> isExist;
  unordered_map<int, deque<int>> sameDestQue;
  deque<tuple<int, int, int>> que;

 public:
  Router(int memoryLimit) { memLimit = memoryLimit; }

  bool addPacket(int source, int destination, int timestamp) {
    tuple<int, int, int> packet = make_tuple(source, destination, timestamp);
    if (isExist.contains(packet)) {
      return false;
    }
    if (length == memLimit) {
      forwardPacket();
    }
    length++;
    que.push_back(packet);
    isExist.insert(packet);
    sameDestQue[destination].push_back(timestamp);
    return true;
  }

  vector<int> forwardPacket() {
    vector<int> data;
    if (!que.empty()) {
      tuple<int, int, int> packet = que.front();
      que.pop_front();
      data = vector<int>{get<0>(packet), get<1>(packet), get<2>(packet)};
      isExist.erase(packet);
      sameDestQue[data[1]].pop_front();
      length--;
    }
    return data;
  }

  int getCount(int destination, int startTime, int endTime) {
    auto pos1 = lower_bound(sameDestQue[destination].begin(),
                            sameDestQue[destination].end(), startTime);
    auto pos2 = upper_bound(sameDestQue[destination].begin(),
                            sameDestQue[destination].end(), endTime);
    return pos2 - pos1;
  }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */