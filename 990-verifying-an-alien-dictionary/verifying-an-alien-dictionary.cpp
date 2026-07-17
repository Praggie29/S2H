class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();
        if (n == 1) return true;
        
        unordered_map<char, int> mpp;
        for (int i = 0; i < 26; i++) {
            mpp[order[i]] = i;
        }
        
        for (int i = 0; i < n - 1; i++) {
            int k = 0, j = 0;
            bool checked = false;
            
            while (k < words[i].size() && j < words[i+1].size()) {
                if (mpp[words[i][k]] > mpp[words[i+1][j]]) {
                    return false;
                } 
                else if (mpp[words[i][k]] < mpp[words[i+1][j]]) {
                    checked = true;
                    break; 
                }
                k++;
                j++;
            }
            
            if (!checked && words[i].size() > words[i+1].size()) {
                return false;
            }
        }
        return true;
    }
};