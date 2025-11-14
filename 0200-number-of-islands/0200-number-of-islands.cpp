class Solution {
    // member variables -- help us explore all possible 4 directions we can go into
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int numIslands(vector<vector<char>>& grid) {
        // declare var to return @ end
        int numIslands = 0;

        // check in the case our grid is empty -- row and col 
        if(grid.empty() || grid[0].empty())
        {
            return 0;
        }

        // grab the dimensions of the grid 
        int rows = grid.size(); 
        int cols = grid[0].size(); 

        // iterating thr our grid 
        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < cols; c++)
            {
                // check if we've found a 1 --> aka an island! 
                if(grid[r][c] == '1')
                {
                    bfs(grid, r, c); 
                    numIslands++;
                }
            }
        }

        return numIslands;
    }

    // HELPER FUNCTION ==
    void bfs(vector<vector<char>>& grid, int row, int col) {
        // 1. declare queue
        queue<pair<int, int>> q;

        // 2. push curr cell to queue 
        q.push({row, col});

        // 3. clear it to avoid reprocessing 
        grid[row][col] = '0';

        // 4. perform bfs 
        while(!q.empty())
        {
            // grab curr cell to process 
            auto cell = q.front();

            // pop it from queue --
            q.pop(); 

            // grab needed info
            int rc = cell.first; 
            int cc = cell.second;

            // check for any neighbors now actually
            for(int i = 0; i < 4; i++)
            {
                int nr = rc + directions[i][0]; 
                int nc = cc + directions[i][1];

                // check if in bounds and if it's an island 
                if((nr >= 0 && nc >= 0) && (nr < grid.size() && nc < grid[0].size()) && (grid[nr][nc] == '1'))
                {
                    q.push({nr, nc});
                    grid[nr][nc] = '0';
                }
            }
        }
    } 
};