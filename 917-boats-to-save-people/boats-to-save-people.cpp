class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort ( people.begin() , people.end() );
        int requiredRescueBoats = 0;
        int l = 0 , r = n - 1;
        while ( l <= r ) {
            int sum = people[l] + people[r];
            if ( sum <= limit ) {
                requiredRescueBoats += 1;
                l++;
                r--;
            }
            else if ( people[l] > people[r] ){
                requiredRescueBoats += 1;
                l++;
            }
            else {
                requiredRescueBoats += 1;
                r--;
            }
        }
        return requiredRescueBoats;
    }
};