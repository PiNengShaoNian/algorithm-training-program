class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int ans = 0;
        for (int p = 1; num1 && num2 && num3; p *= 10) {
            ans += min({num1 % 10, num2 % 10, num3 % 10}) * p;
            num1 /= 10;
            num2 /= 10;
            num3 /= 10;
        }
        return ans;
    }
};