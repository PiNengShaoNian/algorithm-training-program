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
  ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    ListNode dummy;
    dummy.next = head;
    unordered_set<int> nums_set;
    for (int num : nums) {
      nums_set.insert(num);
    }

    ListNode* prev = &dummy;
    while (prev->next) {
      if (nums_set.count(prev->next->val)) {
        prev->next = prev->next->next;
      } else {
        prev = prev->next;
      }
    }

    return dummy.next;
  }
};