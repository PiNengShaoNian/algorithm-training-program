class Solution {
 private:
  unordered_map<int, string> dataBase;
  int id;

 public:
  Solution() { id = 0; }

  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    id++;
    dataBase[id] = longUrl;
    return string("http://tinyurl.com/") + to_string(id);
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) {
    int p = shortUrl.rfind('/') + 1;
    int key = stoi(shortUrl.substr(p, int(shortUrl.size()) - p));
    return dataBase[key];
  }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));s