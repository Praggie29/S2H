class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int matchCount = 0;
        int n = items.size();
        if ( ruleKey == "type") {
            for ( int i = 0 ; i < n ; i ++ ) {
                if ( items[i][0] == ruleValue ) matchCount++;
            }
        }
        else if ( ruleKey == "color" ) {
            for ( int i = 0 ; i < n ; i ++ ) {
                if ( items[i][1] == ruleValue ) matchCount++;
            }
        }
        else {
            for ( int i = 0 ; i < n ; i ++ ) {
                if ( items[i][2] == ruleValue ) matchCount++;
            }
        }
        return matchCount;
    }
};