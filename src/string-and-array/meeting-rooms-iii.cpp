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