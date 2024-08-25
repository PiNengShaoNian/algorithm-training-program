class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        vector<int> cntS(10);
        vector<int> cntG(10);

        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                cntS[secret[i] - '0']++;
                cntG[guess[i] - '0']++;
            }
        }

        int cows = 0;
        for (int i = 0; i < 10; i++) {
            cows += min(cntG[i], cntS[i]);
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};