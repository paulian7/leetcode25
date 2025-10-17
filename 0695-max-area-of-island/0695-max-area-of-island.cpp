class Solution {
    // declare member variable to track the 4 possible directions 
    int directions[4][2] = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // tech: depth first search && recursion

        // time & space comp: 
            // time: o(m * n) -- dimensions of grid 
            // space: o(m * n)
                // in the case all cells are 1's -> dfs will start @ first cell...
                    // then recursively visit every single cell 
                // max recursion depth becomes m x n -> bc each cell will need to be visited 

        // 1. define dimensions of grid 
        int rows = grid.size(); 
        int cols = grid[0].size(); 

        // 2. declare result var to return @ end 
        int maxArea = 0; 

        // 3. start iterating thr grid 
        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < cols; c++)
            {
                // check if we see a 1 (an island)
                if(grid[r][c] == 1)
                {
                    // then perform depth first search to find largest area
                    maxArea = max(maxArea, dfs(grid, r, c));
                }
            }
        }

        // 4. return area for final result 
        return maxArea;
    }

    int dfs(vector<vector<int>>& grid, int r, int c) {
        // w/ recursion -- always handle base case first like: 
            // if we go out of bounds 
            // if we hit water (0)
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == 0)
        {
            return 0; 
        }

        // otherwise, mark current cell as "visited" -- by marking it as a 0 now
        grid[r][c] = 0; 

        // set local variable to return as "area" 
        int currArea = 1; 
        // iterate thr all 4 possible directions w/ this cell 
            // by recursively calling dfs on all 4 neighbors
                // each call checks if in bounds..
                // .. if a 1 
                // ... if yes, then marks visited,
                // .. then explore all its neighbors
        for(int i = 0; i < 4; i++)
        {
            currArea += dfs(grid, r + directions[i][0], c + directions[i][1]);
        }

        return currArea;
    }
};