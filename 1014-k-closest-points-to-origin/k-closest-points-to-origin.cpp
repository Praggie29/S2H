class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
      priority_queue<
            pair<int, vector<int>>, 
            vector<pair<int, vector<int>>>, 
            greater<pair<int, vector<int>>>
        > pq;
        for ( int i = 0 ; i < points.size() ; i++ ) {
            int val = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
            pq.push({val,points[i]});
        }
        while (k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};