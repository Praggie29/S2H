class Solution {
public:
    int findGCD(vector<int>& nums) {
       int minNum = *min_element(nums.begin(),nums.end());
       int maxNum = *max_element(nums.begin(),nums.end());
       while ( minNum > 0 && maxNum > 0 ) {
          if ( minNum > maxNum ) minNum = minNum % maxNum;
          else maxNum = maxNum % minNum;
       }
        if ( minNum == 0 ) return maxNum;
         return minNum;

    }
};