class BookMyShow {
private:
    int n;
    int m;
    // 区间[0, n - 1]行中占用桌位最少的那一行所占用的座位数
    vector<int> minTree;
    // 区间[0, n - 1]行中占用座位的和
    vector<long long> sumTree;

    /**
     * 更新线段树第index号值为val
     * 
     * @param i 当前线段树节点
     * @param l 当前线段树节点的左区间
     * @param r 当前线段树节点的右区间
     * @param index 要更新的位置
     * @param val 更新后的值
     */
    void modify(int i, int l, int r, int index, int val) {
        if (l == r) {
            minTree[i] = val;
            sumTree[i] = val;
            return;
        }

        int mid = (l + r) / 2;
        if (index <= mid) {
            modify(i * 2, l, mid, index, val);
        } else {
            modify(i * 2 + 1, mid + 1, r, index, val);
        }

        minTree[i] = min(minTree[i * 2], minTree[i * 2 + 1]);
        sumTree[i] = sumTree[i * 2] + sumTree[i * 2 + 1];
    }

    /**
     * 查询l到r区间内占用座位数小于等于val的序号最小那一行
     * 
     * @param i 当前线段树节点
     * @param l 当前线段树节点的左区间
     * @param r 当前线段树节点的右区间
     * @param val 占用座位
     * @return 目标行号
     */
    int queryMinRow(int i, int l, int r, int val) {
        if (l == r) {
            if (minTree[i] <= val) {
                return l;
            } else {
                return n;
            }
        }

        int mid = (l + r) / 2;
        if (minTree[i * 2] <= val) {
            return queryMinRow(i * 2, l, mid, val);
        } else {
            return queryMinRow(i * 2 + 1, mid + 1, r, val);
        }
    }

    /**
     * 查询l2到r2区间内占用座位的和
     * 
     * @param i 当前线段树节点
     * @param l 当前线段树节点的左区间
     * @param r 当前线段树节点的右区间
     * @param l2 要累计的左区间
     * @param r2 要累计的右区间
     * @return 座位和
     */
    long long querySum(int i, int l, int r, int l2, int r2) {
        if (l2 <= l && r2 >= r) {
            return sumTree[i];
        }
        int mid = (l + r) / 2;
        long long ans = 0;
        if (mid >= l2) {
            ans += querySum(i * 2, l, mid, l2, r2);
        }

        if (mid + 1 <= r2) {
            ans += querySum(i * 2 + 1, mid + 1, r, l2, r2);
        }

        return ans;
    }
public:
    BookMyShow(int n, int m): n(n), m(m), minTree(4 * n), sumTree(4 * n) {

    }
    
    vector<int> gather(int k, int maxRow) {
        int i = queryMinRow(1, 0, n - 1, m - k);
        if (i > maxRow) {
            return {};
        }
        int used = querySum(1, 0, n - 1, i, i);
        modify(1, 0, n - 1, i, used + k);
        return {i, used};
    }
    
    bool scatter(int k, int maxRow) {
        long long usedTotal = querySum(1, 0, n - 1, 0, maxRow);
        if ((long long)(maxRow + 1) * m - usedTotal < k) {
            return false;
        }
        int i = queryMinRow(1, 0, n - 1, m - 1);
        while (true) {
            long long used = querySum(1, 0, n - 1, i, i);
            if ((m - used) >= k) {
                modify(1, 0, n - 1, i, used + k);
                break;
            }
            k -= (m - used);
            modify(1, 0, n - 1, i, m);
            i++;
        }
        return true;
    }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */