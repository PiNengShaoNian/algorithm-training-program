class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        int mx = max_element(skills.begin(), skills.end()) - skills.begin();
        if (k >= mx) {
            return mx;
        }

        for (int i = 0; i < mx;) {
            int j = i + 1;
            while (skills[j] < skills[i]) j++;
            int win = j - i - (i == 0);
            if (k <= win) {
                return i;
            }
            i = j;
        }
        return mx;
    }
};