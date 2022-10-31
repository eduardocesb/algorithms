class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN) return 0;
        
        bool isNegative = x < 0;
        if(isNegative) x *= -1;
            
        long long res = 0;
        while(x){
            res *= 10;
            res += x % 10;
            x /= 10;
        }
        if(isNegative) res *= -1;
        
        if(INT_MIN <= res && res <= INT_MAX) return (int) res;
        return 0;
    }
};