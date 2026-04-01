class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>> maxHeap;
    int median = 0;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        if (!minHeap.empty() && maxHeap.top() > minHeap.top()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) return maxHeap.top();
        if (minHeap.size() > maxHeap.size()) return minHeap.top();
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};
