class ATM {
private:
    vector<long long> cnt;
    vector<long long> value;
public:
    ATM() {
        cnt = {0, 0, 0, 0, 0};
        value = {20, 50, 100, 200, 500};
    }
    
    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; i++) {
            cnt[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> res(5);
        for (int i = 4; i >= 0; i--) {
            res[i] = min(cnt[i], amount / value[i]);
            amount -= res[i] * value[i];
        }
        if (amount) {
            return {-1};
        } else {
            for (int i = 0; i < 5; i++) {
                cnt[i] -= res[i];
            }
            return res;
        }
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */