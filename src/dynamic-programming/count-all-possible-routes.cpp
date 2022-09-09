class Solution {
public:
    int mod = 1000000007;
    //memo[i][j]表示当前处于locations[i]剩余油量为j可能到达finish的路径
    vector<vector<int>> memo;
    int n;
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        n = locations.size();
        memo.assign(n, vector<int>(fuel + 1, -1));
        return dfs(locations, start, finish, fuel);
    }

    int dfs(vector<int>& locations, int pos, int finish, int rest) {
        if(memo[pos][rest] != -1) return memo[pos][rest];

        memo[pos][rest] = 0;
        if(abs(locations[pos] - locations[finish]) > rest) {
            return 0;
        }

        for(int i = 0; i < n; ++i) {
            int dis = abs(locations[pos] - locations[i]);
            if(i != pos && dis <= rest) {
                memo[pos][rest] += dfs(locations, i, finish, rest - dis);
                memo[pos][rest] %= mod;
            }
        }

        if(pos == finish) {
            memo[pos][rest] += 1;
            memo[pos][rest] %= mod;
        }

        return memo[pos][rest];
    }
};