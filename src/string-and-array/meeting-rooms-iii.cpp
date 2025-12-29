class Solution {
 public:
  int mostBooked(int n, vector<vector<int>>& meetings) {
    vector<long long> roomToAvailableTime(n);
    vector<long long> roomToCnt(n);
    sort(meetings.begin(), meetings.end(),
         [](const vector<int>& a, const vector<int>& b) -> bool {
           return a[0] < b[0];
         });
    for (auto&& meeting : meetings) {
      int start = meeting[0];
      int end = meeting[1];
      bool arranged = false;
      int available = 0;
      for (int i = 0; i < n; i++) {
        if (roomToAvailableTime[i] <= start) {
          roomToAvailableTime[i] = end;
          roomToCnt[i]++;
          arranged = true;
          break;
        }

        if (roomToAvailableTime[i] < roomToAvailableTime[available]) {
          available = i;
        }
      }

      if (!arranged) {
        roomToAvailableTime[available] =
            roomToAvailableTime[available] + (end - start);
        roomToCnt[available] += 1;
      }
    }

    int maxHoldCnt = INT_MIN;
    int maxHoldRoom = -1;
    for (int i = 0; i < n; i++) {
      if (roomToCnt[i] > maxHoldCnt) {
        maxHoldCnt = roomToCnt[i];
        maxHoldRoom = i;
      }
    }
    return maxHoldRoom;
  }
};

class Solution {
 public:
  int mostBooked(int n, vector<vector<int>>& meetings) {
    sort(meetings.begin(), meetings.end(),
         [](const vector<int>& v1, const vector<int>& v2) -> bool {
           return v1[0] < v2[0];
         });
    priority_queue<int, vector<int>, greater<int>> availRooms;
    for (int i = 0; i < n; i++) {
      availRooms.push(i);
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                   greater<>>
        usedRooms;
    vector<int> usedCount(n);
    long long curTime = 0;
    for (const auto& meeting : meetings) {
      curTime = max(curTime, static_cast<long long>(meeting[0]));
      if (availRooms.empty()) {
        curTime = max(curTime, usedRooms.top().first);
      }
      while (!usedRooms.empty() && usedRooms.top().first <= curTime) {
        availRooms.push(usedRooms.top().second);
        usedRooms.pop();
      }
      int room = availRooms.top();
      availRooms.pop();
      usedCount[room]++;
      usedRooms.push({curTime + meeting[1] - meeting[0], room});
    }
    int room = 0;
    for (int i = 0; i < n; i++) {
      if (usedCount[i] > usedCount[room]) {
        room = i;
      }
    }
    return room;
  }
};