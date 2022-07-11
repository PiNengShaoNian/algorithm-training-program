class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int ans = INT_MIN;
        int row1,col1,row2,col2;

        for(int i = 0; i < n; ++i) {
            vector<int> sum(m);
            for(int j = i; j < n; ++j) {
                for(int k = 0; k < m; ++k) {
                    sum[k] += matrix[j][k];
                }

                int presum = 0;
                int presum_min = 0;
                int presum_min_idx = 0;

                for(int k = 0; k < m; ++k) {
                    int x = sum[k];
                    presum += x;
                    if(presum - presum_min > ans) {
                        ans = presum - presum_min;
                        row1 = i;
                        row2 = j;
                        col1 = presum_min_idx;
                        col2 = k;
                    }

                    if(presum < presum_min) {
                        presum_min = presum;
                        presum_min_idx = k + 1; 
                    }
                }
            }
        }

        return {row1, col1, row2, col2};
    }
};