class Solution {
 public:
  string predictPartyVictory(string senate) {
    int n = senate.size();
    queue<int> radiant, dire;
    for (int i = 0; i < n; i++) {
      if (senate[i] == 'R') {
        radiant.push(i);
      } else {
        dire.push(i);
      }
    }

    while (radiant.size() && dire.size()) {
      if (radiant.front() < dire.front()) {
        radiant.push(radiant.front() + n);
      } else {
        dire.push(dire.front() + n);
      }

      radiant.pop();
      dire.pop();
    }

    return radiant.size() ? "Radiant" : "Dire";
  }
};