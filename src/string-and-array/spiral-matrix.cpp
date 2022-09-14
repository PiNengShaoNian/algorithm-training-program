class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();

        int l = 0, r = m - 1, top = 0, bottom = n - 1;

        while(l <= r && top <= bottom) {
            for(int i = l; i <= r; ++i) {
                ans.push_back(matrix[top][i]);
            }

            ++top;
            if(top > bottom) break;

            for(int i = top; i <= bottom; ++i) {
                ans.push_back(matrix[i][r]);
            }

            --r;
            if(r < l) break;

            for(int i = r; i >= l; --i) {
                ans.push_back(matrix[bottom][i]);
            }

            --bottom;
            if(top > bottom) break;

            for(int i = bottom; i >= top; --i) {
                ans.push_back(matrix[i][l]);
            }

            l++;
        }

        return ans;
    }
};