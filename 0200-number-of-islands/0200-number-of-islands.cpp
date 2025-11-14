class Solution {
    // 1. DECLARE SOME MEMBER VARIABLES OF CLASS "SOLUTION" -- that'll help us move around
        // 4 possible directions we can go 
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int numIslands(vector<vector<char>>& grid) {
        // tech: visiting adjacent neighbors side-by-side 
            // perfect for breadth first search (bfs)
        
        // time & space comp:
            // time: o(m * n) 
                // bc going thr matrix -- 
                    // m - num of rows 
                    // n - num of cols
            // space: o(m * n)
        
        // 1. == BASE CASE  perform input validation == 
            // if empty grid -> don't want to perform algo on it 
            // need to check both OUTER and INNER vectors
                // grid.empty() -- 
                    // is what checks for ANY ROWS??
                // grid[0].empty() -- 
                    // is what checks for ANY COLS
        if(grid.empty() || grid[0].empty())
        {
            return 0;
        }

        // 2. grab dimensions of our grid 
        int rows = grid.size();
        int cols = grid[0].size();

        // 3. declare result var to return @ the end 
        int numIslands = 0;

        // 4. start iterating thr each row && col in grid 
        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < cols; c++)
            {
                // check for 1's -- aka possible parts of an island 
                if(grid[r][c] == '1')
                {
                    // perform bfs to search for all connecting 1's neighbor 
                    bfs(grid, r, c); 

                    // increment number of islands after bfs finishes --
                        // iterating thr entire land of that one island
                    numIslands++;
                }
            }
        }

        return numIslands;
    }

    // HELPER FUNCTION ====
    void bfs(vector<vector<char>>& grid, int r, int c) {
        // 1. declare queue for bfs 
            // each element in our queue will hold: row & col
        queue<pair<int, int>> q;

        // 2. take curr val we're @ and set it to 1 
            // ensures we don't accidentally visit this "island" again
        grid[r][c] = '0';

        // 3. add curr element to queue to perform bfs on 
        q.push({r, c});

        // 4. perform bfs to find all adjacent 1's to the og element 
        while(!q.empty())
        {
            // grab curr cell / element 
            auto node = q.front();

            // pop it from queue -- as we're processing it already 
                // no need to store in queue anymore, as queue holds what still needs to be processed
            q.pop();

            // grab curr row && col from curr cell 
            int row = node.first;
            int col = node.second;

            // check for all neighbors of our curr cell
                // where we go in all 4 directions
            for(int i = 0; i < 4; i++)
            {
                // grab NEW ROW after moving in this new direction 
                int nr = row + directions[i][0];

                // grab NEW COL after moving in this new direction
                int nc = col + directions[i][1];

                // ensure NEW ROW && NEW COL are still in the bounds of the grid
                    // AND
                // if they're a '1' (island)
                if((nr >= 0 && nc >= 0) && (nr < grid.size()) && (nc < grid[0].size()) && (grid[nr][nc] == '1'))
                {
                    // add neighboring node that's a '1' to be processed to queue
                    q.push({nr, nc});

                    // set neighboring cell to '0' to avoid reprocessing it again in the future
                    grid[nr][nc] = '0';
                }
            }
        }
    }
};