/*In a gold mine grid of size m * n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:

Every time you are located in a cell you will collect all the gold in that cell.
From your position you can walk one step to the left, right, up or down.
You can't visit the same cell more than once.
Never visit a cell with 0 gold.
You can start and stop collecting gold from any position in the grid that has some gold*/


class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int maxGold = 0;
        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++)
                maxGold = max(maxGold, findMaxGold(grid, m, n, r, c));
        return maxGold;
    }
    int DIR[5] = {0, 1, 0, -1, 0};
    int findMaxGold(vector<vector<int>>& grid, int m, int n, int r, int c) {
        if (r < 0 || r == m || c < 0 || c == n || grid[r][c] == 0) return 0;
        int origin = grid[r][c];
        grid[r][c] = 0; // mark as visited
        int maxGold = 0;
        for (int i = 0; i < 4; i++)
            maxGold = max(maxGold, findMaxGold(grid, m, n, DIR[i] + r, DIR[i + 1] + c));
        grid[r][c] = origin; // backtrack
        return maxGold + origin;
    }
    
};
