class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // tech: breadth first search --> queues! 

        // time & space comp: 
            // time: o(n * m) 
                // will perhaps be calling bfs on multiple points... 
                // ... but still visiting each cell atmost once 
            // space: o(n * m) 
                // same as time comp as well 
                // using a queue -- in the case all oranges rotten
        
        // 1. grab dimensions of grid 
        int rows = grid.size(); 
        int cols = grid[0].size(); 

        // 2. declare queue for bfs
            // holds elements w/ coordinates
        queue<pair<int, int>> q; 

        // 3. track num of fresh oranges
        int freshO = 0;

        // 4. track time 
        int time = 0;

        // 5. iterate thr entire grid -- to do 2 tasks: 
            // count num of fresh oranges
            // queue rotten oranges --> will be running bfs on them later
        for(int r = 0; r < rows; r++)
        {
            for(int c = 0; c < cols; c++)
            {
                // identify fresh vs rotten oranges, mark accordingly 
                if(grid[r][c] == 1)
                {
                    freshO++; 
                }

                if(grid[r][c] == 2)
                {
                    q.push({r, c}); 
                }
            }
        }

        // 6. indicate all poss directions that can be explored 
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // 7. start bfs 
            // while there's still freshO's and rotten orange's to infect those freshO's
        while(freshO > 0 && !q.empty())
        {
            // grab size of queue so far 
            int length = q.size(); 

            // iterate thr until all rotten oranges are popped from queue
                // will be adding any adjacent oranges to the rotten one's to the queue too...
                // ... and marking them rotten
            for(int i = 0; i < length; i++)
            {
                // grab info from first element in queue 
                auto curr = q.front(); 

                // remove first element now from queue (as it's now being processed)
                q.pop(); 

                // grab info more specifically (rows, cols) from elemnt
                int r = curr.first; 
                int c = curr.second; 

                // recursively visit all possible directions from cell 
                for(const auto& dir : directions) 
                {
                    int row = r + dir.first; 
                    int col = c + dir.second; 

                    // check if this new cell from the new direction is: 
                        // in bounds 
                        // is fresh -> to which we'll make rotten 
                    if(row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && grid[row][col] == 1)
                    {
                        // mark this fresh orange ROTTEN now 
                        grid[row][col] = 2; 

                        // add new rotten orange to queue -> will see where infection goes
                        q.push({row, col});

                        // decrement num of fresh oranges
                        freshO--;
                    }
                }
            }

            // increment unit of time 
            time++;
        }

        // 7. return final answer 
            // if num of fresh orange's is 0 --> return the time 
            // else, return -1 (failed)
        return freshO == 0 ? time : -1; 
    }
};