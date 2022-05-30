class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        int minusTwo = 1;
        int minusOne = 2;
        for(int i = 3; i <= n; ++i) {
            int temp = minusOne + minusTwo;
            minusTwo = minusOne;
            minusOne = temp;
        }

        return minusOne;
    }
};