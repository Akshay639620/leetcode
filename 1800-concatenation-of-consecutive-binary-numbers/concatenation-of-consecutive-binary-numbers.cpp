class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans = 0;
        long long MOD = 1000000007;

        for (int i = 1; i <= n; i++) {
            int bits = log2(i) + 1;

            ans = ((ans << bits) + i) % MOD;
        }

        return ans;
    }
};