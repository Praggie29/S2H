class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int>maxHeap(stones.begin(),stones.end()); 
        while ( maxHeap.size() > 1 ) { // priority queue size should be 1
            int a = maxHeap.top(); // gives 1st largest ele from pq
            maxHeap.pop(); // pop that 1st largest ele to safequard from wrong answer
            int b = maxHeap.top(); // gives 2nd largest ele from pq
            maxHeap.pop();
            if ( a != b ) maxHeap.push(abs(a-b));
        }
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};