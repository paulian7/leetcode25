class Solution {
    // declare helper member variables 
        // will cover the 4 possible directions we can go 
        // move down, move up, move left, move right
    int directions[4][2] = {{1,0}, {-1, 0}, {0, -1}, {0, 1}}; 
public:
    int numIslands(vector<vector<char>>& grid) {
        // tech: breadth first search --> queues! 

        // time & space comp: 
            // time: o(m x n) 
            // space: o(m x n) --> dealing w/ 1-big island all added into queue

        // 1. perform input validation -- for edge cases
        if(grid.empty() || grid[0].empty())
        {
            return 0;
        }

        // 2. otherwise, grab dimensions of grid 
        int rows = grid.size(); 
        int cols = grid[0].size();

        // 3. declare result var to return @ end 
        int numIslands = 0;

        // 4. begin iterating thr grid
        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < cols; c++)
            {
                // check for island 
                if(grid[r][c] == '1')
                {
                    bfs(grid, r, c); 

                    numIslands++; 
                }
            }
        }

        return numIslands; 
    }

    // ====== HELPER FUNCTION ======
    void bfs(vector<vector<char>>& grid, int r, int c)
    {
        // 1. declare queue to hold our data for bfs 
            // each element holds 2 pieces of info: 
                // row && col 
        queue<pair<int, int>> q;

        // 2. reset curr cell to 0 -> ensures we don't visit again in future bfs calls
        grid[r][c] = '0'; 

        // 3. add curr cell to queue to perform bfs on 
        q.push({r, c}); 

        // 4. perform bfs algo to find all adjacent 1's 
        while(!q.empty())
        {
            // grab our curr cell -- found in front of queue 
            auto node = q.front(); 

            // now pop it from queue as we're processing it now 
            q.pop(); 

            // grab info from curr cell that was popped off 
            int row = node.first;
            int col = node.second; 

            // explore all 4 possible directions 
            for(int i = 0; i < 4; i++)
            {
                // grab new row 
                int nr = row + directions[i][0]; 
                // grab new col 
                int nc = col + directions[i][1];

                // ensure in bounds && satisfies conditions
                if((nr >= 0 && nc >= 0) && (nr < grid.size()) && (nc < grid[0].size()) && (grid[nr][nc] == '1')) 
                {
                    // add to queue for further processing 
                    q.push({nr, nc}); 

                    // mark as visited now 
                    grid[nr][nc] = '0';
                }
            }
        }
    }
};