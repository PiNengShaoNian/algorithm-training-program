class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> minPQ;
    priority_queue<int, vector<int>, greater<int>> maxPQ;

    MedianFinder() {
    }
    
    void addNum(int num) {
        if(minPQ.empty() || num < minPQ.top()) {
            minPQ.push(num);
            if(maxPQ.size() + 1 < minPQ.size()) {
                maxPQ.push(minPQ.top());
                minPQ.pop();
            }
        }
        else {
            maxPQ.push(num);
            if(maxPQ.size() > minPQ.size()) {
                minPQ.push(maxPQ.top());
                maxPQ.pop();
            }
        }
    }
    
    double findMedian() {
        if(minPQ.size() > maxPQ.size()) {
            return minPQ.top();
        }

        return (minPQ.top() + maxPQ.top()) / 2.0;
    }
};
