/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  int numComponents(ListNode* head, vector<int>& nums) {
    // 只需要计算有多少个组件的起始位置即可
    // 当一个节点满足以下条件之一时，它是组件的起始位置：
    // 1) 节点的值在数组nums中且节点位于链表的起始位置。
    // 2) 节点的值在数组nums中且节点的前一个点不在数组nums中。
    unordered_set<int> numsSet;
    for (int num : nums) {
      numsSet.insert(num);
    }
    bool inSet = false;
    int ans = 0;
    while (head != nullptr) {
      if (numsSet.count(head->val)) {
        if (!inSet) {
          inSet = true;
          ans++;
        }
      } else {
        inSet = false;
      }
      head = head->next;
    }
    return ans;
  }
};