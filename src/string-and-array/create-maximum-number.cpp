class Solution {
 public:
  vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
    int m = nums1.size(), n = nums2.size();
    vector<int> maxSubsequence(k, 0);
    // start: 从nums1中最少需要取多少个元素
    // end: 从nums1中最多可以取多少个元素
    int start = max(0, k - n), end = min(k, m);
    for (int i = start; i <= end; i++) {
      vector<int> subsequence1(MaxSubsequence(nums1, i));
      // 当从nums1中取i个元素时，那么必须从nums2中取k - i个元素
      vector<int> subsequence2(MaxSubsequence(nums2, k - i));
      vector<int> curMaxSubsequence(merge(subsequence1, subsequence2));
      if (compare(curMaxSubsequence, 0, maxSubsequence, 0) > 0) {
        printVec(curMaxSubsequence);
        printVec(subsequence1);
        printVec(subsequence2);
        maxSubsequence.swap(curMaxSubsequence);
      }
    }
    return maxSubsequence;
  }

  // 利用单调栈贪心的获取一个长度为k的子序列
  vector<int> MaxSubsequence(vector<int> &nums, int k) {
    int length = nums.size();
    vector<int> stack(k, 0);
    int top = -1;
    // 当前还可以贪心弹出的元素数量
    int remain = length - k;
    for (int i = 0; i < length; i++) {
      int num = nums[i];
      while (top >= 0 && stack[top] < num && remain > 0) {
        top--;
        remain--;
      }
      if (top < k - 1) {
        stack[++top] = num;
      } else {
        remain--;
      }
    }
    return stack;
  }

  // 将seq1和seq2合并成一个最大的元素
  vector<int> merge(vector<int> &subsequence1, vector<int> &subsequence2) {
    int x = subsequence1.size(), y = subsequence2.size();
    if (x == 0) {
      return subsequence2;
    }

    if (y == 0) {
      return subsequence1;
    }

    /**
     * 当队首元素不相等时选择较大的元素合入，当元素相等时优先合入字典序较大的数组的队首元素
     * 因为消耗的较大数组的元素，可以让其队首后面相对于另外一个数组的较大元素能被合入到比较靠前的元素
     * 考虑以下两个序列
     * seq1: 6, 7 
     * seq2: 6, 0, 4
     * 如果不优先合入seq1的话产生的结果就为
     * 6, 6, 7, 0, 4 
     * 而不是答案
     * 6, 7, 6, 0, 4 
     * */ 
    int mergeLength = x + y;
    vector<int> merged(mergeLength);
    int index1 = 0, index2 = 0;
    for (int i = 0; i < mergeLength; i++) {
      if (compare(subsequence1, index1, subsequence2, index2) > 0) {
        merged[i] = subsequence1[index1++];
      } else {
        merged[i] = subsequence2[index2++];
      }
    }

    return merged;
  }

  // 按字典序比较两个元素(或者说类字典序)
  int compare(vector<int> &subsequence1, int index1, vector<int> &subsequence2,
              int index2) {
    int x = subsequence1.size(), y = subsequence2.size();
    while (index1 < x && index2 < y) {
      int difference = subsequence1[index1] - subsequence2[index2];
      if (difference != 0) {
        return difference;
      }
      index1++;
      index2++;
    }
    return (x - index1) - (y - index2);
  }
};