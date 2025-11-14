class Solution {
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;

        if(grid.empty() || grid[0].empty())
        {
            return 0;
        }

        int rows = grid.size(); 
        int cols = grid[0].size(); 

        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < cols; c++)
            {
                if(grid[r][c] == '1')
                {
                    bfs(grid, r, c); 
                    result++;
                }
            }
        }

        return result;
    }

    void bfs(vector<vector<char>>& grid, int currRow, int currCol) {
        queue<pair<int, int>> q;

        q.push({currRow, currCol});

        grid[currRow][currCol] = '0';

        while(!q.empty())
        {
            auto cell = q.front(); 
            q.pop();

            int r = cell.first;
            int c = cell.second; 

            for(int i = 0; i < 4; i++)
            {
                int nr = r + directions[i][0]; 
                int nc = c + directions[i][1];

                if((nr >= 0 && nc >= 0) && (nr < grid.size() && nc < grid[0].size()) && (grid[nr][nc] == '1'))
                {
                    q.push({nr, nc});
                    grid[nr][nc] = '0';
                }
            }
        }
    }
};