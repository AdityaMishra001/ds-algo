class Solution {
public:
    int m, n;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};
    void dfs(int i, int j, vector<vector<char>>& grid) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] !='O')   return;
        grid[i][j] = '#';
        for(int d = 0; d < 4; d++)
            dfs(i + dx[d], j + dy[d], grid);
    }
    void solve(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1)
                    dfs(i, j, grid);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j]=='O'){
                    grid[i][j]='X';
                }else if(grid[i][j]=='#'){
                    grid[i][j]='O';
                }
                    
        return ;
    }
};