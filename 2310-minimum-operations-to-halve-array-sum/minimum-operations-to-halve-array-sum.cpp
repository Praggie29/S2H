class Solution {
public:
    int halveArray(vector<int>& nums) {
        int n = nums.size();
        double sum = 0;
        for ( int i : nums ) sum += i;
        double halfSum = sum / 2.0;
        priority_queue<double>maxHeap(nums.begin(),nums.end());
        int minOps = 0;
        while ( sum > halfSum ) {
            double a = maxHeap.top();
            maxHeap.pop();
            double halfA = a / 2.0;
            sum -= halfA;
            maxHeap.push(halfA);
            minOps++;
        }
        return minOps;
    }
};