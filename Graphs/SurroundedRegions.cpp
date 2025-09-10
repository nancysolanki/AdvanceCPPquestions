
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        int m = board.size(), n = board[0].size();
        queue<pair<int,int>> q;

        // enqueue border 'O's and mark them '#' (safe)
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') { board[0][j] = '#'; q.push({0,j}); }
            if (board[m-1][j] == 'O') { board[m-1][j] = '#'; q.push({m-1,j}); }
        }
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') { board[i][0] = '#'; q.push({i,0}); }
            if (board[i][n-1] == 'O') { board[i][n-1] = '#'; q.push({i,n-1}); }
        }

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, -1, 0, 1};

        // BFS to mark all 'O's connected to border as '#'
        while (!q.empty()) {
            auto [r,c] = q.front(); q.pop();
            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] == 'O') {
                    board[nr][nc] = '#';
                    q.push({nr, nc});
                }
            }
        }

        // Flip interior 'O' -> 'X' and restore '#' -> 'O'
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};
