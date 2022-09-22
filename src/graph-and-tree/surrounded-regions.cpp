class Solution {
public:
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int rows;
    int cols;
    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();

        for(int i = 0; i < cols; ++i) {
            if(board[0][i] == 'O') mark(0, i, board);
            if(board[rows - 1][i] == 'O') mark(rows - 1, i, board);
        }

        for(int i = 0; i < rows; ++i) {
            if(board[i][0] == 'O') mark(i, 0, board);
            if(board[i][cols - 1] == 'O') mark(i, cols - 1, board);
        }

        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if(board[i][j] == 'T') {
                    board[i][j] = 'O';
                }
                else if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void mark(int row, int col, vector<vector<char>>& board) {
        board[row][col] = 'T';
        for(int i = 0; i < 4; ++i) {
            int newRow = row + dirs[i][0];
            int newCol = col + dirs[i][1];

            if(newRow >= 0 && newRow < rows &&  newCol >= 0 && newCol < cols && board[newRow][newCol] == 'O') {
                mark(newRow, newCol, board);
            }
        }
    }
};

//并查集解法
class Solution1 {
public:
   int dirs [4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
   vector<int> fa;

   inline int vtoi(int i, int j, int cols) {
       return i * cols + j;
   }

   int find (int x) {
        if(fa[x] == x) return x;

        return fa[x] = find(fa[x]);
   };

   void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        fa.resize(n * m + 1);

        for(int i = 0; i < n * m + 1; ++i) {
            fa[i] = i;
        }

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(board[i][j] != 'O') continue;

                for(int k = 0; k < 4; ++k) {
                    int newRow = i + dirs[k][0];
                    int newCol = j + dirs[k][1];

                    if(newRow < 0 || newRow >= n || newCol < 0 || newCol >= m) {
                        fa[find(vtoi(i, j, m))] = fa[find(n * m)];
                    }
                    else if(board[newRow][newCol] == 'O'){
                        fa[find(vtoi(newRow, newCol, m))] = fa[find(vtoi(i, j, m))];
                    }
                }
            }
        }

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(board[i][j] == 'O' && find(vtoi(i, j, m)) != find(n * m)) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

//枚举联通分量解法，如果一个联通分量中所有顶点的邻居都没有出界，那该分量就需要被覆盖
class Solution {
public:
    int cols;
    int rows;
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    struct Point {
        int i;
        int j;
    };
    inline int indexToVertex(int i, int j) {
        return i * cols + j;
    }

    inline Point vertexToIndex(int v) {
        return {v / cols, v % cols};
    }

    inline bool isNeighborOutRange(int i, int j) {
        if(i - 1 < 0 || i + 1 >= rows || j - 1 < 0 || j + 1 >= cols) return true;
        return false;
    }

    void solve(vector<vector<char>>& board) {
        unordered_map<int,vector<int>> idToPoints;
        unordered_map<int,bool> isSurrounded;
        rows = board.size();
        cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        int id = 0;
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if(board[i][j] != 'O' || visited[i][j]) continue;

                vector<int> stack;
                stack.push_back(indexToVertex(i, j));
                isSurrounded[id] = true;

                if(isNeighborOutRange(i, j)) {
                    isSurrounded[id] = false;
                }

                while(stack.size()) {
                    int vertex = stack.back();
                    stack.pop_back();
                    Point p = vertexToIndex(vertex);
                    visited[p.i][p.j] = true;
                    if(idToPoints.find(id) == idToPoints.end()) {
                        idToPoints[id] = move(vector<int>());
                    }
                    
                    idToPoints[id].push_back(vertex);
                    
                    for(int k = 0; k < 4; ++k) {
                        int newI = dirs[k][0] + p.i;
                        int newJ = dirs[k][1] + p.j;

                        if(newI >= 0 && newI < rows && newJ >= 0 && newJ < cols && !visited[newI][newJ] && board[newI][newJ] == 'O') {
                            stack.push_back(indexToVertex(newI, newJ));
                            if(isNeighborOutRange(newI, newJ)) {
                                isSurrounded[id] = false;
                            }
                        }
                    }
                    
                }

                ++id;
            }
        }

        for(auto pair : isSurrounded) {
            if(!pair.second) continue;

            for(int v : idToPoints[pair.first]) {
                Point p = vertexToIndex(v);
                board[p.i][p.j] = 'X';
            }
        } 
    }
};