class Solution {
 public:
  int minSwapsCouples(vector<int>& row) {
    int len = row.size();
    int cnt = 0;
    for (int i = 0; i < len; i++) {
      row[i] = row[i] / 2;
    }

    for (int i = 0; i < len; i += 2) {
      if (row[i] != row[i + 1]) {
        for (int j = i + 2; j < len; j++) {
          if (row[i] == row[j]) {
            swap(row[i + 1], row[j]);
            cnt++;
            break;
          }
        }
      }
    }
    return cnt;
  }
};

class UnionFind {
 private:
  vector<int> data;
  int count;

 public:
  UnionFind(int n) {
    data = vector<int>(n);
    for (int i = 0; i < n; i++) {
      data[i] = i;
    }
    count = n;
  }

  int size() { return count; }

  int find(int x) {
    if (data[x] == x) {
      return x;
    }

    return (data[x] = find(data[x]));
  }

  void connect(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY) {
      return;
    }

    data[rootX] = rootY;
    count--;
  }
};

class Solution {
 public:
  int minSwapsCouples(vector<int>& row) {
    int n = row.size();
    UnionFind uf(n / 2);
    for (int i = 0; i < n; i += 2) {
      uf.connect(row[i] / 2, row[i + 1] / 2);
    }

    return (n / 2) - uf.size();
  }
};