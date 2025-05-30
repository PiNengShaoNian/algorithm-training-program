class Solution {
public:
    bool checkRecord(string s) {
        int absents = 0;
        int lates = 0;
        for (auto ch : s) {
            if (ch == 'A') {
                absents++;
                if (absents >= 2) {
                    return false;
                }
            }
            if (ch == 'L') {
                lates++;
                if (lates >= 3) {
                    return false;
                }
            } else {
                lates = 0;
            }
        }
        return true;
    }
};