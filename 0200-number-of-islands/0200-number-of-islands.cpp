class Solution {
    // MEMBER VARIABLE OF CLASS "SOLUTION" -- 
        // the 4 poss directions we can go: 
            // move down, move up, move right, move left
        // what changes our row / col 
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int numIslands(vector<vector<char>>& grid) {
        // tech: visiting adjacent neighbors side-by-side
            // breadth first search (bfs)! 
        
        // time & space comp: 
            // time: o(m * n)
                // bc goin thr matrix -- 
                // m - num of rows 
                // n - num of columns
            // space: o(m * n)
        
        // 1. perform input validation 
            // if empty grid -> don't want to perform algo on it 
            // need to check both OUTER and INNER vectors
                // grid.empty() --
                    // checks if there's any ROWS
                // grid[0].empty() -- 
                    // checks if there's any columns
        if(grid.empty() || grid[0].empty())
        {
            return 0;
        }

        // 2. grab dimensions of our grid
        int rows = grid.size(); 
        int cols = grid[0].size(); 

        // 3. declare result var for now (num of islands)
        int numIslands = 0;

        // 4. begin iterating thr each row && col in grid 
        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < cols; c++)
            {
                // check for '1's -- aka possible islands
                if(grid[r][c] == '1')
                {
                    // perform bfs to search for all connecting 1's neighbors
                    bfs(grid, r, c); 
                    numIslands++; 
                }
            }
        }

        // 5. return final answer 
        return numIslands;
    }



    // ====== HELPER FUNCTION ====== 
    void bfs(vector<vector<char>>& grid, int r, int c)
    {
        // 1. declare queue to hold our data for bfs
            // each element holds 2 pieces of info: 
                // row && col 
        queue<pair<int, int>> q;

        // 2. reset curr val to 0 --> ensures we don't visit this "island" again in future bfs() calls
        grid[r][c] = '0';

        // 3. NOW, add curr element to queue to perform bfs on 
        q.push({r, c});

        // 4. perform bfs algo to find all adjacent 1's 
        while(!q.empty())
        {
            // grab our curr cell / element 
                // found in front of queue
            auto node = q.front(); 

            // pop this cell from the queue -- as we're processing it rn 
                // no need to store in in queue as a result 
                // queue holds vals to be processed
            q.pop(); 

            // grab row && col from curr cell
            int row = node.first; 
            int col = node.second;

            // check all possible neighbors -- 
                // explore 4 poss directions
            for(int i = 0; i < 4; i++)
            {
                // grab new row index after moving in 1-direction 
                int nr = row + directions[i][0];
                // grab new col index after moving in 1-direction 
                int nc = col + directions[i][1];

                // nr >= 0 && nc >= 0
                    // ensure neighbor cell isn't outside top or left boundary of grid
                // 
                if((nr >= 0 && nc >= 0) && (nr < grid.size()) && (nc < grid[0].size()) && (grid[nr][nc] == '1'))
                {
                    // neighboring node is also a '1' --> add it to queue for further processin'
                    q.push({nr, nc});

                    // set this "NEIGHBORIN' CELL" to avoid re-reading it
                    grid[nr][nc] = '0';
                }
            }

        }
    }
};