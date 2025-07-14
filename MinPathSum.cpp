#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> prev(n, -1);

        for (int i = 0; i < m; i++) {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    prev[j] = temp[j] = grid[i][j];
                    continue;
                }

                int up = grid[i][j];
                int left = grid[i][j];

                if (i > 0) {
                    up += prev[j];
                } else {
                    up = INT_MAX;
                }

                if (j > 0) {
                    left += temp[j - 1];
                } else {
                    left = INT_MAX;
                }

                temp[j] = min(up, left);
            }
            prev = temp;
        }
        return prev[n - 1];
    }
};

int main() {
    Solution sol;

    // Example grid
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    int result = sol.minPathSum(grid);
    cout << "Minimum Path Sum: " << result << endl;

    return 0;
}
