class Solution {
public:
    unordered_map<int, int> f;
    int getF(int x) {
        if (f.find(x) != f.end()) return f[x];
        if (x == 1) {
            return f[x] = 0;
        } else if (x % 2 == 0) {
            return f[x] = 1 + getF(x / 2);
        } else {
            return f[x] = 1 + getF(3 * x + 1);
        }
    }

    int getKth(int lo, int hi, int k) {
        vector<int> v;
        for (int i = lo; i <= hi; i++) {
            v.push_back(i);
        }
        sort(v.begin(), v.end(), [&](int u, int v) {
            if (getF(u) != getF(v)) {
                return getF(u) < getF(v);
            }
            return u < v;
        });
        return v[k - 1];
    }
};