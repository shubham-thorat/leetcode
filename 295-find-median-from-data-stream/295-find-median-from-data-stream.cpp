class MedianFinder {
public:
    priority_queue<int> large;
    priority_queue<int,vector<int>,greater<int>> small;
    bool even;
    MedianFinder() {
        // large.clear();
        // small.clear();
        even = true;
    }
    
    void addNum(int num) {
        
        if(even) {
            small.push(num);
            int largeValuefromleft = small.top();
            small.pop();
            large.push(largeValuefromleft);
        }
        else {
            large.push(num);
            int smallValuefromright = large.top();
            large.pop();
            small.push(smallValuefromright);
        }
        even = !even;
    }
    
    double findMedian() {
        if(even) {
            int u = large.top();
            int v = small.top();
            return (u + v)/2.0;
        }
        else {
            return large.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */