class Solution {
public:
    int countDigits(int num) {
       int digCount = 0;
       int temp = num;
       while ( temp ) {
         int rem = temp % 10;
         if ( num % rem == 0 ) {
            digCount ++;
         }
         temp /= 10;
       } 
       return digCount; 
    }
};