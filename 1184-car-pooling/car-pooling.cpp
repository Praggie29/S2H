class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int diff[1001]={0};
        for(auto &it:trips){
            int cnt=it[0];
            int start=it[1];
            int end=it[2];
            diff[start]+=cnt;
            diff[end]-=cnt;
        }
        int sum=0;
        for(int i=0;i<1001;i++){
            sum+=diff[i];
            if(sum>capacity) return false;
        }
        return true;
    }
};