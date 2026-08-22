class Solution {
public:
    int findProduct ( int num ) {
        int temp = num;
        int prodSum = 1;
        while ( temp ) {
            int rem = temp % 10;
            prodSum *= rem;
            temp /= 10;
        }
        return prodSum;
    }
    int findSum ( int num ) {
        int temp = num;
        int digSum = 0;
        while ( temp ) {
            int rem = temp % 10;
            digSum += rem;
            temp /= 10;
        }
        return digSum;
    }
    bool checkDivisibility(int n) {
        int sum = findSum(n);
        int prod = findProduct(n);
        int totalSum = sum + prod;
        return n % totalSum == 0 ;
    }
};