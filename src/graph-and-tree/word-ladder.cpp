class Solution {
public:
    //层序遍历解法
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        deque<string> q;
        int wordLen = beginWord.size();
        unordered_set<string> allWords;
        int steps = 1;
        for(auto &word : wordList) {
            allWords.insert(word);
        }

        if(allWords.find(endWord) == allWords.end()) return 0;

        q.push_back(beginWord);
        allWords.erase(beginWord);
        while(true) {
            deque<string> nextQ;
            while(q.size()) {
                string cur = q.front();
                q.pop_front();
    
                vector<string> neighbors;
                for(auto &word : allWords) {
                    int diff = 0;

                    for(int i = 0; i < wordLen; ++i) {
                        if(word[i] != cur[i]) ++diff;

                        if(diff > 1) break;
                    }

                    if(diff == 1) {
                        neighbors.push_back(word);
                    }
                }

                for(string &word : neighbors) {
                    if(word == endWord) {
                        return steps + 1;
                    }
                    nextQ.push_back(word);
                    allWords.erase(word);
                }
            }
            
            if(nextQ.size() == 0) break;
            q = move(nextQ);
            ++steps;
        }

        return 0;
    }
};