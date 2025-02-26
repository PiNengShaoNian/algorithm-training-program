class BrowserHistory {
    private:
        vector<string> urls;
        int currentIdx;
    public:
        BrowserHistory(string homepage) {
            urls.push_back(homepage);
            currentIdx = 0;
        }
        
        void visit(string url) {
            while (urls.size() > currentIdx + 1) {
                urls.pop_back();
            }
            urls.push_back(url);
            currentIdx++;
        }
        
        string back(int steps) {
            currentIdx = max(0, currentIdx - steps);
            return urls[currentIdx];
        }
        
        string forward(int steps) {
            currentIdx = min(int(urls.size() - 1), currentIdx + steps);
            return urls[currentIdx];
        }
    };
    
    /**
     * Your BrowserHistory object will be instantiated and called as such:
     * BrowserHistory* obj = new BrowserHistory(homepage);
     * obj->visit(url);
     * string param_2 = obj->back(steps);
     * string param_3 = obj->forward(steps);
     */