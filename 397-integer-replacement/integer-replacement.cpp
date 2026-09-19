class Solution {
public:
    int integerReplacement(int n) {
        long long x = n;
        int cnt = 0;
        while (x > 1) {
            if ((x & 1) == 0) {
                x = x >> 1;
            } else {
                if (x == 3)
                    x--;
                else if ((x & 2) != 0)
                    x++;
                else
                    x--;
            }
            cnt++;
        }
        return cnt;
    }
};