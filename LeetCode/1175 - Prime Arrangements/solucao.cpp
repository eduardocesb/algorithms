//https://leetcode.com/problems/prime-arrangements/

class Solution {
public:
    
    bool isPrime(int N)
    {
        if(N < 2) return false;
        
        int root = sqrt(N);
        
        for(int i = 2; i <= root; i++)
            if(!(N % i)) return false;
        
        return true;
    }
    
    int numPrimeArrangements(int n) {
        long long MOD = 1000000007;
        long long fat[n + 1];
        fat[0] = 1;
        
        int K = 0;
        
        for(int i = 1; i <= n; i++)
            fat[i] = (1LL * i * fat[i - 1]) % MOD, K += isPrime(i);
        
        int r = (fat[K] * fat[n - K]) % MOD;
        
        return r;
    }
};