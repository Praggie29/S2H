class Solution {
public:
    void f ( int i ,vector<int>&candidates , vector<int>& store , vector<vector<int>>& ans , int target ) {
        if ( i == candidates.size() || target < 0 ) return ;
        if ( target == 0 ) {
            ans.push_back(store);
            return;
        }
        store.push_back(candidates[i]);
        f ( i  , candidates , store , ans , target - candidates[i] );
        store.pop_back();
        f ( i + 1 , candidates , store , ans , target );
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>store;
        vector<vector<int>>ans;
        f ( 0 , candidates , store , ans , target );
        return ans;
    }
};