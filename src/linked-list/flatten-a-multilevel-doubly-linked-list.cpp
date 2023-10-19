/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
 public:
  Node *flatten(Node *head) {
    function<Node *(Node *)> dfs = [&](Node *node) {
      Node *cur = node;
      // 记录链表的最后一个节点
      Node *last = nullptr;

      while (cur) {
        Node *next = cur->next;
        // 如果有子节点，那么首先处理子节点
        if (cur->child) {
          Node *child_last = dfs(cur->child);
          next = cur->next;
          // 将node与child相连
          cur->next = cur->child;
          cur->child->prev = cur;

          //  如果 next 不为空，就将 last 与 next 相连
          if (next) {
            child_last->next = next;
            next->prev = child_last;
          }

          // 将child置为空
          cur->child = nullptr;
          last = child_last;
        } else {
          last = cur;
        }
        cur = next;
      }
      return last;
    };

    dfs(head);
    return head;
  }
};