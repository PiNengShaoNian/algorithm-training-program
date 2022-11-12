class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> vec;
        for(auto& row : matrix) {
            for(int n : row) {
                vec.push_back(n);
            }
        }

        sort(vec.begin(), vec.end());
        return vec[k - 1];
    }
};

//利用归并排序的思路将n行数组依次归并，并用小顶堆作为归并的容器每在队尾加入一个元素
//就从堆顶删除一个元素删，除第k-1次时堆顶的元素就是答案
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        struct point {
            int i, j, val;
            point(int _i, int _j, int _val): i(_i), j(_j), val(_val) {}
            bool operator>(const point& right) const {
                return this->val > right.val;
            }
        };
        priority_queue<point, vector<point>, greater<point>> pq;
        int n = matrix.size();
        for(int i = 0; i < n; ++i) {
            pq.emplace(i, 0, matrix[i][0]);
        }

        for(int i = 0; i < k - 1; ++i) {
            point top = pq.top();
            pq.pop();
            if(top.j + 1 < n) {
                pq.emplace(top.i, top.j + 1, matrix[top.i][top.j + 1]);
            }
        }

        return pq.top().val;
    }
};

//二分查找解法
class Solution {
public:
    //计算出该矩阵中有多少元素小于等于mid时间复杂度O(n)
    bool check(vector<vector<int>> &matrix, int mid, int n, int k) {
        int i = n - 1;
        int j = 0;
        int count = 0;
        while(i >= 0 && j < n) {
            if(matrix[i][j] <= mid) {
                count += i + 1;
                ++j;
            } else {
                --i;
            }
        }

        return count >= k;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0];
        int r = matrix[n - 1][n - 1];
        int ans = -1;
        while(l <= r) {
            int mid = l + ((r - l) >> 1);
            if(check(matrix, mid, n, k)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};