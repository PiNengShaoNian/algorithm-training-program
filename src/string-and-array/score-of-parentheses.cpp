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