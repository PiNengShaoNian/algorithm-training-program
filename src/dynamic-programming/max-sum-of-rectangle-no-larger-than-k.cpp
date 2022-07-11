class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();

        int ans = INT_MIN;
        for(int i = 0; i < n; ++i) {
            vector<int> sum(m);
            for(int j = i; j < n; ++j) {
                for(int k = 0; k < m; ++k) {
                    sum[k] += matrix[j][k];
                }

                int presum = 0;
                set<int> presum_set = {0};

                for(int num : sum) {
                    presum += num;
                    //(1) presum - *lb <= k 
                    //(2) presum - k <= *lb (和等式1等价)
                    //要求在满足不等式(1)的情况下，让等式左部尽可能大等价于
                    //在满足等式(2)的情况下，*lb尽可能小

                    //在这里求出的lb能保证，满足不等式(2)且还是其中最小的
                    auto lb = presum_set.lower_bound(presum - k); 
                    if(lb != presum_set.end()) {
                        ans = max(ans, presum - *lb);
                    }

                    presum_set.insert(presum);
                }
            }
        }

        return ans;
    }
};