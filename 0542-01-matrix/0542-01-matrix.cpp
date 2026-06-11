class Solution {
    using pii = pair<int,int>;
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>>dist(m, vector<int>(n, -1));
        queue<pii>q;
        // push all zeroes
        for(int i = 0; i <m;i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0)
                    q.push({i, j}), dist[i][j] = 0;
            }
        }

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        // vector<vector<int>>dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        // vector<int> dirs = {-1, 0, 1, 0, -1};

        while(!q.empty()){
            pii p = q.front();
            q.pop();
            int i = p.first, j = p.second;
            for(int d = 0; d < 4; d++){
                int ni = i + dx[d], nj = j + dy[d];
                if(ni >= 0 && ni < m && nj >= 0 && nj < n)
                    if(dist[ni][nj] == -1)
                        dist[ni][nj] = dist[i][j] + 1, q.push({ni, nj});
            }
        }
        return dist;
    }
};