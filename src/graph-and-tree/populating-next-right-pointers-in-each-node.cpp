class Solution {
 public:
  Node* connect(Node* root) {
    if (root == nullptr) {
      return root;
    }

    Node* leftmost = root;

    while (leftmost->left != nullptr) {
      // 遍历这一层节点组织成的链表，为下一层的节点更新 next 指针
      Node* head = leftmost;

      while (head != nullptr) {
        head->left->next = head->right;

        if (head->next != nullptr) {
          head->right->next = head->next->left;
        }

        // 指针向后移动
        head = head->next;
      }

      // 去下一层的最左的节点
      leftmost = leftmost->left;
    }

    return root;
  }
};