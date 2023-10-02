class Solution {
 private:
  int mutate(vector<char>& chars, int cnt, int l, char c) {
    chars[l++] = c;
    if (cnt == 1) {
      return l;
    }
    string s = to_string(cnt);
    for (char c : s) {
      chars[l++] = c;
    }

    return l;
  }

 public:
  int compress(vector<char>& chars) {
    int idx = 0;
    chars.push_back('\0');
    int n = chars.size();
    char curChar = -1;
    int cnt = 0;
    int last = 0;
    while (idx < n) {
      if (chars[idx] != curChar && curChar != -1) {
        last = mutate(chars, cnt, last, curChar);
        cnt = 0;
      }

      curChar = chars[idx];
      cnt++;
      idx++;
    }

    return last;
  }
};