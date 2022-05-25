class Solution {
public:
    int numberOfWays(int numPeople) {
        long long *dp = (long long*)malloc(sizeof(long long) * (numPeople + 1));
        int MOD = 1e9 + 7;
        dp[0] = 1;
        
        //枚举不同的人数(只能是偶数)
        for(int i = 2; i <= numPeople; i += 2) {
            dp[i] = 0;

            //我们将握手的一个人固定为i(最大的人数)，然后枚举和他握手的另一个人，
            //这两个人会把剩下的人分为两部分，第一部分人有j-1个人，第二部分有i-j-1个人
            //因为不能有相交所以i这能和1,3,5,7,i-1这些人握手(即要保证分割后的两部分人数均为偶数)
            //考虑如下情况i=4:
            //此时我们枚举另一个人为1,即分割后的第一部分人为[],第二部分人为[2,3]
            //如果我们枚举的人为2,这是不合法的，此时分割后的第一部分人就为[1],第二部分人为[3]
            //他们之间握手必定会产生相交            
            for(int j = 1; j < i; j+=2) {
                dp[i] = (dp[i] + (dp[j - 1] * dp[i - j - 1]) % MOD) % MOD;
            }
        }

        return dp[numPeople];
    }
};