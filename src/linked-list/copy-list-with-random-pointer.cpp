/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    //使用一个额外Map的解法
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        unordered_map<Node*, Node*> old_to_new;
        vector<Node*> nodes;
        for(Node *cur = head; cur; cur = cur->next) {
            old_to_new[cur] = new Node(cur->val);
        }

        for(Node* cur = head; cur; cur = cur->next) {
            Node* new_node = old_to_new[cur];
            Node* next = cur->next == nullptr ? nullptr : old_to_new[cur->next];
            new_node->next = next;
            new_node->random = cur->random == nullptr ? nullptr : old_to_new[cur->random];
        }

        return old_to_new[head];
    }

    //O(1)空间复杂度解法
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;

        for(Node* cur = head; cur; cur = cur->next->next) {
            Node* newNode = new Node(cur->val);
            newNode->next = cur->next;
            cur->next = newNode;
        }

        for(Node* cur = head; cur; cur = cur->next->next) {
            cur->next->random = cur->random ? cur->random->next : nullptr; 
        }

        Node dummyHead(-1);
        Node *tail = &dummyHead;
        for(Node *cur = head; cur; cur = cur->next) {
            tail =  tail->next = cur->next;
            cur->next = tail->next;
        }

        return dummyHead.next;
    }
};