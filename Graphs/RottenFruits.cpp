class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        queue<pair<pair<int,int>,int>> q;
        int m=grid.size();
        int n =grid[0].size();
         vector<vector<int>> visited(m, vector<int>(n, 0));
        int count= 0;

        for(int i =0 ; i<m ; i ++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j]==2){
                   q.push({{i, j}, 0});
                    visited[i][j]=1;
                }
            }
        }

        vector<int>dr={-1,0,1,0};
        vector<int>dc={0,-1,0,1};

        while (!q.empty()) {
    auto curr = q.front();
    q.pop();

    int r = curr.first.first;
    int c = curr.first.second;
    int t = curr.second;
    count = max(count, t);

    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr >= 0 && nr < m && nc >= 0 && nc < n && visited[nr][nc] == 0 && grid[nr][nc] == 1) {
            visited[nr][nc] = 1;
            grid[nr][nc] = 2;
            q.push({{nr, nc}, t + 1});
        }
    }
}
        for(int i =0 ; i<m ; i ++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }


    return count;

    }
};
