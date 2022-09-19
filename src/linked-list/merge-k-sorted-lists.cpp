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
    ListNode* merge(ListNode* l1, ListNode *l2) {
        ListNode dummy_head;
        ListNode* cur = &dummy_head;
        while(l1 || l2) {
            if(l1 == nullptr) {
               cur->next = l2;
               break; 
            }
            else if(l2 == nullptr) {
                cur->next = l1;
                break;
            }
            else if(l2->val < l1->val) {
                cur->next = l2;
                cur = l2;
                ListNode *next_l2 = l2->next;
                l2->next = nullptr;
                l2 = next_l2;
            }
            else {
                cur->next = l1;
                cur = l1;
                ListNode *next_l1 = l1->next;
                l1->next = nullptr;
                l1 = next_l1;
            }
        }

        return dummy_head.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode* ans = nullptr;

        for(int i = 0; i < n; ++i) {
            ans = merge(ans, lists[i]);
        }

        return ans;
    }
};

//使用额外空间的优先队列解法，时间复杂度为O(N),其中N为所有节点的数量
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto less = [](ListNode* a, ListNode* b) -> bool {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(less)> pq(less);

        for(auto l : lists) {
            for(ListNode* cur = l; cur; cur = cur->next) {
                pq.push(cur);
            }
        }

        ListNode dummy_head;
        ListNode* cur = &dummy_head;
        while(pq.size()) {
            ListNode* min_node = pq.top();
            pq.pop();
            min_node->next = nullptr;
            cur->next = min_node;
            cur = min_node;
        }

        return dummy_head.next;
    }
};