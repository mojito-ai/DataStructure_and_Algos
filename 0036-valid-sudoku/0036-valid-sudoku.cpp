class Solution {
public:
    /*
    * Brute Force: Take element (i,j) and then check for any repitition
    * 1. Check from (i, j -> [1,9])
    * 2. Check from (i->[1,9], j)
    * 3. Check in the box -> i range [(i-1/3*3)+1, (i-1/3*3)+2] j range [(j-1/3*3)+1, (j-1/3*3)+2]
    */

    /*
    * Optimised Approach: 
    */
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i<9; i++) {
            for(int j = 0; j<9; j++) {
                if(board[i][j] != '.') {
                    for(int col=0; col<9; col++) {
                        if (col == j) continue;
                        else if (board[i][j] == board[i][col]) return false;
                    }
                    for(int row=0; row<9; row++) {
                        if (row == i) continue;
                        else if (board[i][j] == board[row][j]) return false;
                    }
                    for(int row = (int)(i/3) * 3; row <= ((int)(i/3)*3)+2; row++) {
                        for(int col = (int)(j/3)*3; col <= ((int)(j/3)*3)+2; col++) {
                            if (row == i && col == j) continue;
                            else if (board[i][j] == board[row][col]) return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};