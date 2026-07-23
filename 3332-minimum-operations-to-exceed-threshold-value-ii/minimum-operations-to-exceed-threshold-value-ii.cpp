class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> minHeap(nums.begin(), nums.end());
        long long minOps = 0;
        while(minHeap.top() < k ) {
           long long a = minHeap.top();
           minHeap.pop();
           long long b = minHeap.top();
           minHeap.pop();
           long long val = ( a * 2 ) + b;
           minHeap.push(val);
           minOps++;
        }
        return minOps;
    }
};