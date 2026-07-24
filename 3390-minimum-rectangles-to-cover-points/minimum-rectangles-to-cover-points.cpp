class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(),points.end());
        int n = points.size();
        int ans = 0;
        int i = 0;
        while ( i < n ) {
            int a = points[i][0];
            int b = a + w;
            ans++;
            while ( i < n && points[i][0] <= b ) {
                i++;
            }
        }
        return ans;
    }
};