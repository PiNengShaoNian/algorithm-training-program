//记忆化搜索
class Solution {
public:
    int n;
    int d;
    vector<int> memo;
    int maxJumps(vector<int>& arr, int _d) {
        int ans = 1;
        n = arr.size();
        d = _d;
        memo = vector<int>(n, -1);
        for(int i = 0; i < n; ++i) {
            ans = max(ans, dfs(arr, i));
        }

        return ans;
    }
    
    int dfs(vector<int>& arr, int cur) {
        if(memo[cur] != -1) return memo[cur];
        int ans = 0;
        for(int i = 1; i <= d; ++i) {
            if(cur - i < 0 || arr[cur - i] >= arr[cur]) break;

            ans = max(ans, dfs(arr, cur - i));
        }

        for(int i = 1; i <= d; ++i) {
            if(cur + i >= n || arr[cur + i] >= arr[cur]) break;

            ans = max(ans, dfs(arr, cur + i));
        }

        return memo[cur] = ans + 1;
    }
};