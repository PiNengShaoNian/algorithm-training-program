class SkiplistNode {
    public:
        SkiplistNode* right = nullptr;
        SkiplistNode* down = nullptr;
        int val;
    

    SkiplistNode(int val): val(val) {}
};

class Skiplist {
private:
    mt19937 gen{random_device{}()};
    std::uniform_real_distribution<double> dist {0.0, 1.0};
    uniform_real_distribution<double> dis;
    vector<SkiplistNode *> heads;
    vector<SkiplistNode *> tails;

public:
    Skiplist() {
        for (int i = 0; i <= 15; i++) {
            tails.push_back(new SkiplistNode(INT_MAX));
            heads.push_back(new SkiplistNode(INT_MIN));
        }

        for (int i = 0; i < 15; i++) {
            heads[i]->right = tails[i];
            heads[i]->down = heads[i + 1];
            tails[i]->down = tails[i + 1];
        }

        heads[15]->right = tails[15];
    }
    
    bool search(int target) {
        SkiplistNode *cur = heads[0];
        while (cur) {
            if (cur->right->val < target) {
                cur = cur->right;
            } else if (cur->right->val > target) {
                cur = cur->down;
            } else {
                return true;
            }
        }

        return false;
    }
    
    void add(int num) {
        vector<SkiplistNode*> stack;
        SkiplistNode *cur = heads[0];
        while (cur) {
            if (cur->right->val > num) {
                stack.push_back(cur);
                cur = cur->down;
            } else {
                cur = cur->right;
            }
        }

        SkiplistNode *pre = nullptr;
        while (!stack.empty()) {
            SkiplistNode *cur = stack.back();
            stack.pop_back();
            SkiplistNode *newNode = new SkiplistNode(num);
            newNode->right = cur->right;
            cur->right = newNode;
            newNode->down = pre;

            pre = newNode;

            if (dist(gen) < 0.5) {
                break;
            }
        }
    }
    
    bool erase(int num) {
        SkiplistNode *cur = heads[0];
        bool isRemoved = false;

        while (cur) {
            if (cur->right->val >= num) {
                if (cur->right->val == num) {
                    isRemoved = true;
                    SkiplistNode *right = cur->right;
                    cur->right = right == nullptr ? nullptr : right->right;
                    if (right) {
                        delete right;
                    }
                }
                cur = cur->down;
            } else {
                cur = cur->right;
            }
        }

        return isRemoved;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */