class Solution {
public:
    void f(int i, vector<int>& candidates, int target, int currentSum, vector<int>& store, vector<vector<int>>& ans) {
        if (currentSum > target || i == candidates.size()) {
            if (currentSum == target) {
                ans.push_back(store);
            }
            return;
        }

        store.push_back(candidates[i]);
        f(i, candidates, target, currentSum + candidates[i], store, ans);

        store.pop_back();

        f(i + 1, candidates, target, currentSum, store, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> store;
        vector<vector<int>> ans;
        f(0, candidates, target, 0, store, ans);
        return ans;
    }
};