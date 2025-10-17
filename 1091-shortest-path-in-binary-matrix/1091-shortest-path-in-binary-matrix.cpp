class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // tech: breadth first search to find shortest path
            // 8-directions: left, right, up, down, diagonals (4) --> 8 in total
            // want to find shortest path from (0, 0) to (n - 1, n - 1) thr only 0's
            // else, return -1 if not possible

        // time & space comp: 
            // time: o(n^2)
                // size of grid 
            // space: o(n ^2) 
                // in the case we have entire grid loaded into queue
        
        // 1. set up dimensions of grid -- just N bc we have a square grid (n x n)
        int N = grid.size(); 

        // cover edge cases + have helper variable for directions we can go 
        if(grid[0][0] == 1 || grid[N - 1][N - 1] == 1) return -1; 

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0},
                                             {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

        // 2. declare some helper data structures -- 
            // queue - for bfs 
            // 2d vector -- to track of cells we've already visited -> 
                // .. so we don't get stuck in infinte loop
        queue<tuple<int, int, int>> q; 

        // have all cells set to false for now
            // vector<vector<bool>>(N, ...) - creates N rows 
            // vector<bool>(N, false) - creates N cols -> each col initialized to false
        vector<vector<bool>> visitedCells(N, vector<bool>(N, false)); 

        // 3. push first element to queue 
            // tuple - {row, col, length} 
        q.push({0, 0, 1});

        // 4. set first element as visited now
        visitedCells[0][0] = true; 

        // 5. start bfs
        while(!q.empty())
        {
            // grab first element from queue 
            auto [r, c, length] = q.front();

            // pop off first element afterwards -- since it's now being processed
            q.pop(); 

            // check if reached BOTTOM-RIGHT CELL 
            if(r == N - 1 && c == N - 1) 
            {
                // then return final answer 
                return length;
            }

            // otherwise, check in all directions 
            for(auto [dr, dc] : directions)
            {
                int nr = r + dr; 
                int nc = c + dc; 

                // check for bounds 
                if(nr >= 0 && nc >= 0 && nr < N && nc < N && grid[nr][nc] == 0 && !visitedCells[nr][nc])
                {
                    // pass all conditions -> add to queue for processing 
                        // rmbr to increase length (to track shortest path)
                    q.push({nr, nc, length + 1}); 

                    // set this new cell as visited now 
                    visitedCells[nr][nc] = true;
                }
            }
        }

        // 6. else, if can't find length -> return -1
        return -1; 
    }
};