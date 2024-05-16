class Solution {
 public:
  int scoreOfParentheses(string s) {
    stack<int> st;
    st.push(0);

    for (auto c : s) {
      if (c == '(') {
        st.push(0);
      } else {
        int v = st.top();
        st.pop();
        st.top() += max(1, 2 * v);
      }
    }

    return st.top();
  }
};

class Solution {
 public:
  int scoreOfParentheses(string s) {
    int bal = 0;
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
      bal += (s[i] == '(' ? 1 : -1);
      if (s[i] == ')' && s[i - 1] == '(') {
        ans += 1 << bal;
      }
    }
    return ans;
  }
};