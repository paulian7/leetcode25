class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // tech: lots of hash sets here! 
            // checking if val already in that row 
            // if val already in that col
            // if val already in the 3x3 square 

        // 1. declare row and column respec hash table
            // key: column or row number in overall 9x9 
            // value: all values in that column or row
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> cols;

        // 2. create a map - tracks each of the 3x3 squres
            // maps - maintain order; lookups slower than hashtables (takes logn)
            // key: set of grid coordinates (row, col) 
            // val: tracks chars already in that spec square 
        map<pair<int, int>, unordered_set<char>> squares;

        // 3. iterate thr entire grid now (9x9 dimensions)
            // have 9 rows, 9 cols 
        for (int r = 0; r < 9; r++) {
            // iterate thr each col within the row 
            for (int c = 0; c < 9; c++) {
                // check if any empty spaces --> yes, skip to next col in row (aka go to next iteration)
                if (board[r][c] == '.') continue;
                
                // identify what 3x3 grid we're dealing w/ this curr val 
                pair<int, int> squareKey = {r / 3, c / 3};

                // 1) check if curr char is seen in row...
                // 2) or entire column 
                // 3) or within the entire 3x3 grid it's in 
                // ... then invalid suduko! 
                if (rows[r].count(board[r][c]) || cols[c].count(board[r][c]) || squares[squareKey].count(board[r][c])) {
                    return false;
                }

                // otherwise... curr val is VALID! --> now update our trackers~ 
                    // will help us ensure that this currVal won't appear again in the...
                        // .. same row / col / grid 
                rows[r].insert(board[r][c]);
                cols[c].insert(board[r][c]);
                squares[squareKey].insert(board[r][c]);
            }
        }

        // passed all tests --> valid suduko! 
        return true;
    }
};