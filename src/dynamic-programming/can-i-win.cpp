class Solution {
public:
    vector<int> memo;
    int max;
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger >= desiredTotal) return true;
        //如果所有可选数字的和还没有desiredTotal大，可以直接返回false
        if ((maxChoosableInteger * (maxChoosableInteger + 1)) / 2 < desiredTotal)
            return false;

        max = maxChoosableInteger;
        memo.resize(1 << max, -1);
        return solve(0, desiredTotal);      
    }

    //由于maxChoosableInteger最大为20，所以我们可以用二十位bit组成的状态来表示数字的选择情况
    //比如第i位bit为1的话就表示数字i+1已经被选择
    //solve(s, remaining)表示在选了数字的情况为s时，且desiredTotal为remaining时
    //先手的玩家能否获胜，虽然有两个状态但是s和remaining这两个状态时等价的，在选了的
    //数字固定的情况下和他对应的remaining一定是唯一且固定的，所以用s作为缓存的key即可
    bool solve(int s, int remaining) {
        if(memo[s] != -1) return memo[s];

        for(int i = 0; i < max; ++i) {
            int pick = 1 << i;

            //这个数字已经被选了，不能再次被选
            if((s & pick) != 0) continue;

            //如果我们选择的这个数字已经大于desiredTotal,或者后手的玩家在下一个的状态上会输
            //那么在s这个状态下先手就一定能赢
            if((i + 1) >= remaining || solve(s | pick, remaining - (i + 1)) == false) {
                return memo[s] = 1;
            }
        }

        return memo[s] = 0;
    }
};