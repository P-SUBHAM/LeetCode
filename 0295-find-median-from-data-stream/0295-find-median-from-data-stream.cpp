class MedianFinder {
public:
    priority_queue<double,vector<double>,greater<>> rightpq;
    priority_queue<double> leftpq;
    int cnt;
    MedianFinder() {
        leftpq = priority_queue<double>();
        rightpq = priority_queue<double,vector<double>,greater<>>();
        cnt = 0;
    }
    
    void addNum(int num) {
        cnt++;
        leftpq.push(num);
        int leftVal = leftpq.top();
        if(rightpq.size() >= 1 && leftpq.top() > rightpq.top()) {
            leftVal = leftpq.top(); leftpq.pop();
            int rightVal = rightpq.top(); rightpq.pop();
            leftpq.push(min(leftVal,rightVal));
            rightpq.push(max(leftVal,rightVal));
        }
        if(leftpq.size() > rightpq.size() + 1) { // bal l > r
            leftVal = leftpq.top(); leftpq.pop();
            rightpq.push(leftVal);
        }
    }
    
    double findMedian() {
        if(cnt%2 == 1) {
            return leftpq.top();
        }
        return (leftpq.top()+rightpq.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */