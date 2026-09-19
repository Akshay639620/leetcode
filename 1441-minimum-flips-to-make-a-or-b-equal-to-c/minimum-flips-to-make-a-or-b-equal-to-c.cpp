class Solution {
public:
    int minFlips(int a, int b, int c) {
        long long flips = 0;
        long long x = a;
        long long y = b;
        long long z = c;
        while (x != 0 || y != 0 || z != 0) {
            if ((z & 1) == 1) {
                if ((x & 1) == 0 && (y & 1) == 0)
                    flips++;
            } else {
                if ((x & 1) == 1)
                    flips++;
                if ((y & 1) == 1)
                    flips++;
            }

            x >>= 1;
            y >>= 1;
            z >>= 1;
        }
        return flips;
    }
};