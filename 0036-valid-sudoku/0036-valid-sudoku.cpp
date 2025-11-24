class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // tech: hash sets -> easy to identify duplicates in: 
            // the curr row 
            // the curr col
            // the 3x3 it's in
        
        // time & space comp:  
            // time:
            // space: 
        
        // 1. declare hash table for entire row && col within 9x9 grid
        unordered_map<int, unordered_set<char>> row;
        unordered_map<int, unordered_set<char>> col;

        // 2. declare a separate map to track each 3x3 grid respectively
        map<pair<int, int>, unordered_set<char>> square;

        // 3. iterate thr the 9x9 grid now
        // iterate thr each row
        for(int r = 0; r < 9; r++)
        {
            // then iterate thr each col
            for(int c = 0; c < 9; c++)
            {
                // check for empty boxes (.) --> skip to next iteration if empty
                if(board[r][c] == '.') continue;

                // check now for what 3x3 grid it is in the overall 9x9 
                pair<int, int> squareKey = {r / 3, c / 3};

                // else, check for duplicates in the 3 scenarios
                if(row[r].count(board[r][c]) || col[c].count(board[r][c]) || square[squareKey].count(board[r][c]))
                {
                    return false;
                }

                // if no dups, add it to the hashSets for later reference 
                row[r].insert(board[r][c]);
                col[c].insert(board[r][c]);

                square[squareKey].insert(board[r][c]);
            }
        }

        // if all iterations finished, passed tests -> valid suduko
        return true;
    }
};