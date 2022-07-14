class Solution {
public:
	//O(R ^ 2 * C ^ 2)
	int countCornerRectangles(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		int ans = 0;

		for (int rowStart = 0; rowStart < n; ++rowStart) {
			for (int colStart = 0; colStart < m; ++colStart) {
				if (grid[rowStart][colStart] == 0) continue;
				for (int row = 2; row + rowStart <= n; ++row) {
					if (grid[rowStart + row - 1][colStart] == 0) continue;
					for (int col = 2; col + colStart <= m; ++col) {
						if (grid[rowStart][colStart + col - 1] && grid[rowStart + row - 1][colStart + col - 1]) {
							++ans;
						}
					}
				}
			}
		}

		return ans;
	}

    //O(R * C ^ 2)
	int countCornerRectangles1(vector<vector<int>>& grid) {
        // pos = col1 << 8 + col2;
        // count[pos]表示当前grid中col1和col2都为1的行的数量
		unordered_map<int, int> count;
		int n = grid.size();
		int m = grid[0].size();
		int ans = 0;

		for (int i = 0; i < n; ++i) {
			auto& row = grid[i];

			for (int col1 = 0; col1 < m; ++col1) {
				if (row[col1] == 1) {
					for (int col2 = col1 + 1; col2 < m; ++col2) {
						if (row[col2] == 1) {
							int pos = (col1 << 8) + col2;
							int c = count[pos];

							ans += c;
							count[pos] = c + 1;
						}
					}
				}
			}
		}

		return ans;
	}
};