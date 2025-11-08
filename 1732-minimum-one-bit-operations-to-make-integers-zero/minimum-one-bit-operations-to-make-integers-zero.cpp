class Solution {
    private:
    int helper(int n) {
        if (n == 0) return 0;
        int x = 1;
        while ((x << 1) <= n) {
            x <<= 1;
        }
        int highMask = x | (x >> 1);
        return helper(n ^ highMask) + 1 + (x - 1);
    }

public:
    int minimumOneBitOperations(int n) {
        return helper(n);
        
    }
};