class Solution {
public:
    long long gcd ( int a , int b ) {
        while ( a != 0 && b != 0 ) {
            if ( a > b ) a = a % b;
            else b = b % a;
        }
        if ( a == 0 ) return b;
        return a;
    }
    long long gcdSum(vector<int>& nums) {
        vector<long long >maxGCD;
        int maxi = INT_MIN;
        for ( int i = 0 ; i < nums.size() ; i ++ ) {
            maxi = max ( maxi , nums[i] );
            int ele = gcd ( maxi , nums[i] );
            maxGCD.push_back(ele);
        }
        sort ( maxGCD.begin() , maxGCD.end());
        long long gcdSum = 0;
        int i = 0 , j = maxGCD.size() - 1;
        while ( i < j ) {
            gcdSum += gcd ( maxGCD[i] , maxGCD[j] );
            i++;
            j--;
        }
        return gcdSum;
    }
};