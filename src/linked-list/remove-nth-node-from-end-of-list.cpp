class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int size = 0;

        ListNode *cur = head;
        while (cur)
        {
            cur = cur->next;
            ++size;
        }

        n = size - n;

        if (n == 0)
        {
            return head->next;
        }

        cur = head;
        ListNode *pre = nullptr;
        for (int i = 0; i < n; ++i)
        {
            pre = cur;
            cur = cur->next;
        }

        pre->next = cur->next;
        cur->next = nullptr;

        return head;
    }
};