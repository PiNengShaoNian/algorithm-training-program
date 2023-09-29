class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int i = 0;
    while (i < n) {
      int cnt = 0;
      int sumOfGas = 0;
      int sumOfCost = 0;
      while (cnt < n) {
        int j = (i + cnt) % n;
        sumOfGas += gas[j];
        sumOfCost += cost[j];

        if (sumOfCost > sumOfGas) {
          break;
        }
        cnt++;
      }

      if (cnt == n) {
        return i;
      } else {
        i = i + cnt + 1;
      }
    }

    return -1;
  }
};