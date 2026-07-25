class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOnes = 0;
        int currentSum = 0;

        for (int num : nums) {
            if (num == 1) {
                currentSum++;
                maxOnes = max(maxOnes, currentSum); 
            } else {
                currentSum = 0; 
            }
        }

        return maxOnes;
    }
};