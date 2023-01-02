struct TrieNode {
    int count;
    unordered_map<char, TrieNode*> next; 
    char word;
};

class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *cur = root;
        for(auto &c : word) {
            if(!cur->next.count(c)) {
                cur->next[c] = new TrieNode();
            }
            cur = cur->next[c];
        }

        cur->count++;
    }
    
    bool search(string word) {
        TrieNode *cur = root;
        for(auto &c : word) {
            if(!cur->next.count(c)) {
                return false;
            }

            cur = cur->next[c];
        }

        return cur->count > 0;
    }
    
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for(auto &c : prefix) {
            if(!cur->next.count(c)) {
                return false;
            }

            cur = cur->next[c];
        }

        return true;
    }
};
