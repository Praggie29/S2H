class Solution {
public:
    int countOdds(int low, int high) {
        int oddCnt = 0;
        for ( int i = low ; i <= high ; i ++ ) {
            if ( i % 2 == 1 ) oddCnt++;
        }
        return oddCnt;
    }
};