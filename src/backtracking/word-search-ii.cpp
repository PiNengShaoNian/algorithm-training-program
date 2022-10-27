struct TrieNode {
    string word;
    unordered_map<char, TrieNode*> children;
    TrieNode() {
        this->word = "";
    }
};

void insertTrieNode(TrieNode* root,string word) {
    for(auto c : word) {
        if(!root->children.count(c)) {
            root->children[c] = new TrieNode();
        }

        root = root->children[c];    
    }

    root->word = word;
}

class Solution {
public:
    unordered_set<string> res;
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(auto &word : words) {
            insertTrieNode(root, word);
        }
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                dfs(i, j, root, board);
            }
        }

        vector<string> ans;

        for(const string& word : res) {
            ans.push_back(word);
        }

        return ans;
    }

    void dfs(int i, int j, TrieNode* cur,  vector<vector<char>>& board) {
        char ch = board[i][j];

        if(cur->children.count(ch) == 0) {
            return;
        }

        TrieNode* next = cur->children[ch];
        if(next->word.size() > 0) {
            res.insert(next->word);
        }

        if(next->children.size() == 0) {
            cur->children.erase(ch);
            return;
        }

        board[i][j] = '#';

        for(int k = 0; k < 4; ++k) {
            int newI = i + dirs[k][0];
            int newJ = j + dirs[k][1];

            if(newI >= 0 && newI < board.size() && newJ >= 0 && newJ < board[0].size() && board[newI][newJ] != '#') {
                dfs(newI, newJ, next, board);   
            }
        }

        board[i][j] = ch;
    }
};