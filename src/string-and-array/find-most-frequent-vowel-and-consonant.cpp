class Solution {
 public:
  int maxFreqSum(string s) {
    int cnt[26] = {0};
    for (char c : s) {
      cnt[c - 'a']++;
    }

    int maxVowel = 0;
    int maxConsonant = 0;
    for (int i = 0; i < 26; i++) {
      char c = i + 'a';
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        maxVowel = max(maxVowel, cnt[i]);
      } else {
        maxConsonant = max(maxConsonant, cnt[i]);
      }
    }
    return maxVowel + maxConsonant;
  }
};