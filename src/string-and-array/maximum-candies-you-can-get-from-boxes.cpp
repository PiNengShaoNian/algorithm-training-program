class Solution {
 public:
  int maxCandies(vector<int>& status, vector<int>& candies,
                 vector<vector<int>>& keys, vector<vector<int>>& containedBoxes,
                 vector<int>& initialBoxes) {
    enum {
      CAN_NOT_OPEN = 0B000,

      OPENED_OR_HAVE_KEY = 0B001,
      HAVE_BOX = 0B010,

      OPENED = OPENED_OR_HAVE_KEY | HAVE_BOX,

      GETTED_CANDY = 0B100
    };

    for (auto had_box : initialBoxes) {
      status[had_box] |= HAVE_BOX;
    }

    int ans = 0;

    auto dfs = [&](auto&& dfs, int current_box) {
      auto& current_box_state = status[current_box];

      if (current_box_state != OPENED) {
        return;
      }

      ans += candies[current_box];
      current_box_state |= GETTED_CANDY;

      for (auto have_key : keys[current_box]) {
        status[have_key] |= OPENED_OR_HAVE_KEY;

        dfs(dfs, have_key);
      }

      for (auto have_box : containedBoxes[current_box]) {
        status[have_box] |= HAVE_BOX;

        dfs(dfs, have_box);
      }
    };

    const int length = status.size();
    for (auto i = length - 1; i >= 0; i--) {
      dfs(dfs, i);
    }

    return ans;
  }
};