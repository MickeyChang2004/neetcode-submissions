class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int nums[9][9];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    nums[i][j] = 0;
                } else {
                    nums[i][j] = board[i][j] - '0';
                }
            }
        }
        for (int i = 0; i < 9; i++) {
            unordered_set<int> seen_row;
            for (int j = 0; j < 9; j++) {
                if (nums[i][j] != 0) {
                    if (seen_row.contains(nums[i][j])) {
                        return false;
                    } else {
                        seen_row.insert(nums[i][j]);
                    }
                }
            }
        }
        for (int i = 0; i < 9; i++) {
            unordered_set<int> seen_column;
            for (int j = 0; j < 9; j++) {
                if (nums[j][i] != 0) {
                    if (seen_column.contains(nums[j][i])) {
                        return false;
                    } else {
                        seen_column.insert(nums[j][i]);
                    }
                }
            }
        }
        for (int box = 0; box < 9; box++) {
            int start_row = (box / 3) * 3;
            int start_column = (box % 3) * 3;
            unordered_set<int> seen_grid;

            for (int i = start_row; i < start_row + 3; i++) {
                for (int j = start_column; j < start_column + 3; j++) {
                    if (nums[i][j] != 0) {
                        if (seen_grid.contains(nums[i][j])) {
                            return false;
                        }
                        seen_grid.insert(nums[i][j]);
                    }
                }
            }
        }
        return true;
    }
};
