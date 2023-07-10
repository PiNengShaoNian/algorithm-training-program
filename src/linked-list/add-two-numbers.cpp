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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *dummy = new ListNode();
        ListNode *curr = dummy;
        #define VAL(node) (node ? node->val : 0)
        #define NEXT(node) (node ? node->next : nullptr)

        while(l1 || l2) {
            int n = VAL(l1) + VAL(l2) + carry;
            l1 = NEXT(l1);
            l2 = NEXT(l2);
            ListNode *temp = new ListNode(n % 10);
            curr->next = temp;
            curr = temp;
            carry = n >= 10 ? 1 : 0;            
        }

        if(carry) {
            curr->next = new ListNode(1);
        }

        ListNode *ans = dummy->next;
        delete dummy;
        return ans;
    }
};