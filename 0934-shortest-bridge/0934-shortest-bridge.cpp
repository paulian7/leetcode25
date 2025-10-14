class Solution {
public:
    // tech: breadth first search && depth first search 
        // 1) DFS search -- to find and mark our first island... will know where to start now
        // 2) BFS search -- then expand outwards from that first island til we reach the sec island
            // bc bfs expands evenly in all directions --> first time it touches other island will be...
                // the guranteed shortest path
        // .. the num of layers (aka expansions outwards) that we expand in BFS... 
            // will be the shortest number of flips --> aka our SOLUTION! :)

     // time & space comp: 
        // time:
        // space:

    // === 1. DECLARE SOME MEMBER VARIABLES TO HELP === 
    // var to grab dimensions of grid 
    int N; 
    
    // tracks which cells we've visited / not visited
    vector<vector<bool>> visited; 
    
    // poss directions we can go 
        // move right, move left, move down, move up
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // === function given by question ===
    int shortestBridge(vector<vector<int>>& grid) {
        // 1. initalize dimensions of grid 
        N = grid.size(); 

        // 2. initialize what nodes have been visited && not visited 
            // creating a N x N grid of false vals TO START OFF WITH
        visited = vector<vector<bool>>(N, vector<bool>(N, false));

        // 3. iterate thr grid to find our FIRST LAND CELL :)
        bool found = false; 
        for(int r = 0; r < N; r++)
        {
            if(found) break; // break out of loop entirely

            for(int c = 0; c < N; c++)
            {
                // once we reach land (aka 1) -- run dfs asap 
                    // dfs will mark all cells belonging to this island as visited
                if(grid[r][c] == 1) 
                {
                    dfs(grid, r, c); 

                    // set found to true --> so we don't mark the second island w/ dfs algo here
                    found = true;

                    // break out of the for-loop
                    break;
                }
            }
        }

        // after finding the first island thr dfs --> perform bfs 
            // will find shortest path (minimum flips) to the other island 
        return bfs(grid);
    }


private: 
    // HELPER FUNCTIONS 
    // ====== DEPTH FIRST SEARCH ALGO FUNCTION ======
    void dfs(vector<vector<int>>& grid, int r, int c)
    {
        // check if curr cell is out of bounds or not a 1 or we've already seen this cell
        if(r < 0 || c < 0 || r >= N || c >= N || grid[r][c] == 0 || visited[r][c])
        {
            return; // return immediately, don't want to do dfs on this cell
        }

        // else, set our curr cell to having already been visited
        visited[r][c] = true;
        // now visit all possible directions recursively
        for(auto& d : directions)
        {
            dfs(grid, r + d[0], c + d[1]);
        }
    }

    // ====== BREADTH FIRST SEARCH ALGO FUNCTION ======
    int bfs(vector<vector<int>>& grid)
    {
        // declare queue like always w/ any bfs algo 
            // each element holds: 
                // row && col vals
        // will push all cells of the first island (found thr dfs earlier) ONTO QUEUE
        queue<pair<int, int>> q;
        for(int r = 0; r < N; r++) 
        {
            for(int c = 0; c < N; c++)
            {
                if(visited[r][c])
                {
                    q.push({r, c});
                }
            }
        }

        // have var to return as shortest bridge fINAL RESULT
            // tracks the number of layers we've expanded in BFS 
            // aka what we're returning as result
        int result = 0; 
        
        // start processing queue -- will start expanding outwards from the island
            // queue holds the curr layer of cells we're exploring
        while(!q.empty())
        {
            // q.size() -- tells us how many cells are in curr layer
            for(int i = q.size(); i > 0; i--)
            {
                // process elements from queue 
                auto [r, c] = q.front(); 

                // then pop as we've processed it 
                q.pop(); 

                // now expand in all directions 
                for(auto& d : directions)
                {
                    int currRow = r + d[0]; 
                    int currCol = c + d[1]; 

                    // check if in bounds or if been visited 
                        // if not in bounds or visited already -> skip to next iteration 
                    if(currRow < 0 || currCol < 0 || currRow >= N || currCol >= N || visited[currRow][currCol])
                    {
                        continue;
                    }

                    // check if we've reached the second island yet.. if == to 1 --> then yes
                    if(grid[currRow][currCol] == 1) 
                    {
                        // returns num of layers we've expanded so far... 
                            // .. so the minimum flips (so bridge length)
                        return result;
                    }

                    // otherwise, keep expanding.. 
                    // so push curr cell onto queue to process next layer of BFS 
                    q.push({currRow, currCol});

                    // and mark curr cell as visited (so we don't revisit it in the future)
                    visited[currRow][currCol] = true;
                }
            }

            // finished expanding 1-full ring of distance... 
                // now increment 1 
            result++; 
        }

        return result;
    }
};