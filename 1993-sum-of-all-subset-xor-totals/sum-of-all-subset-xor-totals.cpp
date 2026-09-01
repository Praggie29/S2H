class Solution {
public:
   void f ( int i , vector<int>&nums , int n , int &totalSum , int sum ) {
      if ( i == n ) {
         totalSum += sum;
         return;
      }
      f ( i + 1 , nums , n , totalSum , sum ^ nums[i] );
      f ( i + 1 , nums , n , totalSum , sum );

   }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        f ( 0 , nums , n , totalSum , 0 );
        return totalSum;
    }
};