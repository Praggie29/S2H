class Solution {
public:
    int f ( int num ) {
        if ( num < 1 ) return 0;
        if ( num == 1 ) return 1;
        return f ( num - 1 ) + f ( num - 2 );
    }
    int fib(int n) {
        if ( n == 0 ) return 0;
        if ( n == 1 ) return 1;
        return f(n-1) + f(n-2);
    }
};