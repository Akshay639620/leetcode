class Solution {
public:
    typedef long long ll;
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < m; j++) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }

        for (int i = 1; i < m; i++) {
            int cntzeros = 0;
            for (int j = 0; j < n; j++) {
                if (grid[j][i] == 0)
                    cntzeros++;
            }
            int cntone = n - cntzeros;
            if (cntzeros > cntone) {
                for (int j = 0; j < n; j++) {
                    grid[j][i] = 1 - grid[j][i];
                }
            }
        }

        int score = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int value = 1ll * grid[i][j] * pow(2, m - j - 1);
                score += value;
            }
        }
        return score;
    }
};