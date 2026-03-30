class KthLargest {
    int size;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    KthLargest(int k, vector<int>& nums) : size(k) {
        for (int n : nums) {
            minHeap.push(n);
        }
        while (minHeap.size() > size) minHeap.pop();
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > size)
        {
            minHeap.pop();
        }
        return minHeap.top();
    }
};
