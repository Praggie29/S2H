class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int>elesLesserThanPivot;
        vector<int>elesGreaterThanPivot;
        vector<int>elesEqualToPivot;
        for ( int i = 0 ; i < n ; i ++ ) {
            if ( nums[i] < pivot ) elesLesserThanPivot.push_back(nums[i]);
            else if ( nums[i] > pivot ) elesGreaterThanPivot.push_back(nums[i]);
            else elesEqualToPivot.push_back(nums[i]);
        }
        vector<int>ans;
        int i = 0 , j = 0 , k = 0;
        while ( i < elesLesserThanPivot.size() ) {
            ans.push_back(elesLesserThanPivot[i]);
            i++;
        }
        while ( j < elesEqualToPivot.size() ) {
            ans.push_back(elesEqualToPivot[j]);
            j++;
        }
        while ( k < elesGreaterThanPivot.size() ) {
            ans.push_back(elesGreaterThanPivot[k]);
            k++;
        }
        return ans;
    }
};