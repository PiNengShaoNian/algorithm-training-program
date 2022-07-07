class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i = n - 2; i >= 0; --i) {
            for(int j = 0; j < m; ++j) {
                int min_num = matrix[i + 1][j];
                min_num = j - 1 >= 0 ? min(matrix[i + 1][j - 1], min_num) : min_num;

                min_num = j + 1 < m ? min(matrix[i + 1][j + 1], min_num) : min_num; 

                matrix[i][j] += min_num; 
            }
            
        }


        return *min_element(matrix[0].begin(), matrix[0].end());
    }
};