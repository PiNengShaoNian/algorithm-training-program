//滑动窗口解法
class Solution {
public:
    bool less(int a[], int b[], int n) {
        for(int i = 0; i < n; ++i) {
            if(a[i] < b[i]) return true;
        }

        return false;
    }

    string minWindow(string s, string t) {
        int t_count[58];
        int n = s.size();
        int m = t.size();
        memset(t_count, 0, sizeof(t_count));

        for(int i = 0; i < m; ++i) {
            ++t_count[t[i] - 'A'];
        }

        int window[58];
        memset(window, 0, sizeof(window));
        int len = n + 1;
        int start = -1;

        int r = -1;
        int l = 0;

        while(l < n) {
            bool is_meet = !less(window, t_count, 58);
            if(r + 1 < n && !is_meet) {
                ++window[s[++r] - 'A'];
            }
            else {
                if(r - l + 1 < len && is_meet) {
                    len = r - l + 1;
                    start = l;
                }
                --window[s[l] - 'A'];
                ++l;
            }
        }

        return len == n + 1 ? "" : s.substr(start, len);
    }
};