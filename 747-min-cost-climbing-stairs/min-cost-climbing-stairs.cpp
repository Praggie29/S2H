class Solution {
public:
    int f ( int i , vector<int>&cost , vector<int>&dp ) {
        if ( i >= cost.size() ) return 0;
        if ( i == cost.size() - 1 ) return cost[cost.size()-1];
        if ( dp[i] != -1 ) return dp[i];
        int a = cost[i] + f ( i + 1 , cost , dp );
        int b = cost[i] + f ( i + 2 , cost , dp );
        return dp[i] = min ( a , b );
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        int firstStep = f ( 0 , cost , dp1 );
        int secondStep = f ( 1 , cost , dp2 );
        return min ( firstStep , secondStep );
    }
};