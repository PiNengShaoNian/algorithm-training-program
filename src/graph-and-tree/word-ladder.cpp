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

//双向BFS解法
class Solution {
public:
	unordered_map<string, string> edgeTo;

	int expand(unordered_map<string, int>& distTo, unordered_map<string, int>& otherDistTo, queue<string>& q) {
		queue<string> nextQ;
		while (q.size()) {
			string cur = q.front();
			q.pop();
			int wordLen = cur.size();
			int depth = distTo[cur];
			for (int i = 0; i < wordLen; ++i) {
				string cand = cur;
				for (int j = 0; j < 26; ++j) {
					cand[i] = 'a' + j;

					if (distTo.find(cand) == distTo.end()) continue;

					if (otherDistTo[cand] != INT_MAX) {
						return depth + otherDistTo[cand];
					}

					if (depth + 1 < distTo[cand]) {
						nextQ.push(cand);
						distTo[cand] = depth + 1;
					}
				}
			}
		}

		while (nextQ.size()) {
			q.push(nextQ.front());
			nextQ.pop();
		}
		return -1;
	}
    
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_map<string, int> distToStart;
		unordered_map<string, int> distToEnd;
		queue<string> queueStart;
		queue<string> queueEnd;

		for (auto& word : wordList) {
			distToStart[word] = INT_MAX;
			distToEnd[word] = INT_MAX;
		}

		if (distToStart.find(endWord) == distToStart.end()) return 0;

		queueStart.push(beginWord);
		queueEnd.push(endWord);
		distToStart[beginWord] = 1;
		distToEnd[endWord] = 1;
		distToEnd[beginWord] = INT_MAX;
		distToStart[endWord] = INT_MAX;
		while (queueStart.size() || queueEnd.size()) {
			int res = expand(distToStart, distToEnd, queueStart);

			if (res != -1) return res;

			res = expand(distToEnd, distToStart, queueEnd);

			if (res != -1) return res;
		}

		return 0;
	}
};
