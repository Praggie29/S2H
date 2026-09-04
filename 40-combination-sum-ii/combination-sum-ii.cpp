class Solution {
public:
    void f ( int start , vector<int>& candidates, vector<int>&store , vector<vector<int>>&ans , int target ) {
        if ( target == 0 ) {
            ans.push_back(store);
            return;
        }
        for ( int i = start ; i < candidates.size() ; i ++ ) {
            if ( i > start && candidates[i] == candidates[i-1]) continue;
            if ( candidates[i] > target ) break;
                store.push_back(candidates[i]);
                f ( i + 1 , candidates , store , ans , target - candidates[i] );
                store.pop_back(); 
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int n = candidates.size();
        vector<int>store;
        vector<vector<int>>ans;
        f ( 0 , candidates , store , ans , target );
        return ans;
    }
};