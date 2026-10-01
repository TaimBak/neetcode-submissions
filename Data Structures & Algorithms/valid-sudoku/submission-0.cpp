class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Use a hash map to check each row and column for duplicates O(n)

        // Use some silly for loop manipulation to offset row/col by three to validate each 3x3 block. Becomes a 3x3 grid that will perform 9 total validations, first all three block in each row before moving to the next col.

        // Use a blockId to cover the 3x3 blocks along with three separate hash maps to do the whole table in one pass. (blockID = (r / 3) * 3 + c / 3)

        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> cols;
        unordered_map<int, unordered_set<char>> blocks;

        for (int r = 0; r < 9; r++)
            for (int c = 0; c < 9; c++)
            {
                char cell = board[r][c];
                
                if (cell == '.')
                    continue;

                int blockId = (r / 3) * 3 + c / 3;

                // all three validity checks
                if    (rows[r].contains(cell) ||                       cols[c].contains(cell) ||                       blocks[blockId].contains(cell)) 
                            return false;

                rows[r].insert(cell);
                cols[c].insert(cell);
                blocks[blockId].insert(cell);
            }

        
        return true;
    }
};
