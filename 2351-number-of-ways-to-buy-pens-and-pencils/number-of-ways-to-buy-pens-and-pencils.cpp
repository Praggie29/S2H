class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long waysToPurchase = 0;
        for (long long i = 0; i * cost1 <= total; i++) {
            long long remaining = total - (i * cost1);
            long long maxPencils = remaining / cost2;
            waysToPurchase += (maxPencils + 1);
        }
        
        return waysToPurchase;
    }
};