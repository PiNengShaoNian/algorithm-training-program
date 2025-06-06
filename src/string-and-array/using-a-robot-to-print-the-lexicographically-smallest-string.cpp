class Solution {
 public:
  string robotWithString(string s) {
    int n = s.size();
    vector<char> suf_min(n + 1);
    suf_min[n] = 'z';
    for (int i = n - 1; i >= 0; i--) {
      suf_min[i] = min(suf_min[i + 1], s[i]);
    }

    string ans;
    stack<char> st;
    for (int i = 0; i < n; i++) {
      st.push(s[i]);
      while (!st.empty() && st.top() <= suf_min[i + 1]) {
        ans += st.top();
        st.pop();
      }
    }

    return ans;
  }
};