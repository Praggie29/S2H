class Solution {
public:
    int sumOfPrimesInRange(int n) {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        int nn = stoi(s);
        
        int mini = min(n, nn);
        int maxi = max(n, nn);
        
        // Sieve of Eratosthenes up to maxi
        vector<bool> isPrime(maxi + 1, true);
        if (maxi >= 0) isPrime[0] = false;
        if (maxi >= 1) isPrime[1] = false;
        
        for (int i = 2; i * i <= maxi; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= maxi; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        long long primeNumsSum = 0;
        for (int i = mini; i <= maxi; i++) {
            if (isPrime[i]) {
                primeNumsSum += i;
            }
        }
        
        return primeNumsSum;
    }
};