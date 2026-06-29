class Solution {
public:
    const int MOD = 1e9 + 7;
    
    // Function to calculate (base^exp) % MOD in O(log exp) time
    long long power(long long base, long long exp) {
        long long result = 1;
        base = base % MOD;
        
        while (exp > 0) {
            // If exp is odd, multiply the base with the result
            if (exp % 2 == 1) {
                result = (result * base) % MOD;
            }
            // Square the base and halve the exponent
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long even_count = (n + 1) / 2;
        long long odd_count = n / 2;
        
        long long even_combinations = power(5, even_count);
        long long odd_combinations = power(4, odd_count);
        
        return (even_combinations * odd_combinations) % MOD;
    }
};