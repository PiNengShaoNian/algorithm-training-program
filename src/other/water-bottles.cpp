class Solution {
 public:
  int numWaterBottles(int numBottles, int numExchange) {
    int ans = numBottles;
    int emptyBottles = numBottles;

    while (emptyBottles >= numExchange) {
      int bottles = emptyBottles / numExchange;
      ans += bottles;
      emptyBottles -= (bottles * numExchange);
      emptyBottles += bottles;
    }
    return ans;
  }
};