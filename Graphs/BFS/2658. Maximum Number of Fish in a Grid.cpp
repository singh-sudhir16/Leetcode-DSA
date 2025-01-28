class Solution {
public:
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxi = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    
                    int tmp = 0;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    tmp += grid[i][j];
                    grid[i][j] = 0; // Mark as visited

                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();

                        for (auto dir : dirs) {
                            int nx = x + dir[0];
                            int ny = y + dir[1];

                            if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] > 0) {
                                q.push({nx, ny});
                                tmp += grid[nx][ny];
                                grid[nx][ny] = 0; // Mark as visited
                            }
                        }
                    }
                    maxi = max(maxi, tmp);
                }
            }
        }

        return maxi;
    }
};
