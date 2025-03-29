class Solution {
    public:
        int longestCycle(vector<int>& edges) {
            int n = edges.size();
            vector<int> label(n);
            int current_label = 0, ans = -1;
            for (int i = 0; i < n; i++) {
                if (label[i]) {
                    continue;
                }
                int pos = i; 
                int start_label = current_label;
                while (pos != -1) {
                    current_label++;
                    if (label[pos]) {
                        if (label[pos] > start_label) {
                            ans = max(ans, current_label - label[pos]);
                        }
                        break;
                    }
                    label[pos] = current_label;
                    pos = edges[pos];
                }
            }
            return ans;
        }
    };