class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for (int i : nums) {
            mpp[i]++;
        }

        int duplicateVal = -1;
        int missingEle = -1;

        for (int i = 1; i <= n; i++) {
            if (mpp[i] == 2) {
                duplicateVal = i;
            } else if (mpp[i] == 0) {
                missingEle = i;
            }
        }

        return {duplicateVal, missingEle};
    }
};