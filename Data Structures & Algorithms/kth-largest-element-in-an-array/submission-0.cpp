class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>> heap;

        for (int num : nums)
        {
            heap.push(num);
        }

        int c = 1;
        
        while (c < k)
        {
            heap.pop();
            c++;
        }

        return heap.top();
    }
};
