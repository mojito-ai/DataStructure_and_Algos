class Solution {
public:
    /*
    * Brute Force: Take element (i,j) and then check for any repitition
    * 1. Check from (i, j -> [1,9])
    * 2. Check from (i->[1,9], j)
    * 3. Check in the box -> i range [(i-1/3*3)+1, (i-1/3*3)+2] j range [(j-1/3*3)+1, (j-1/3*3)+2]
    */

    /*
    * Optimised Approach: Precomputation
    * Traverse the 2D array and make a hashmap for entries_row and entries_col and entries_box
    * When you arrive at (i,j) then find if arr[i][j] exists in entries_row[i] && entries_col[j] && entries_box
    * Instead of checking rows, columns, and boxes separately every time, you precompute and store the presence of numbers in:
    * 1. entries_row[i] → Tracks numbers present in row i
    * 2. entries_col[j] → Tracks numbers present in column j
    * 3. entries_box[boxIndex] → Tracks numbers in its respective 3×3 box
    */
    bool isValidSudoku(vector<vector<char>>& board) {
        return optimised_approach(board);
    }

    bool optimised_approach(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> entries_row;
        unordered_map<int, unordered_set<char>> entries_col;
        unordered_map<int, unordered_set<char>> entries_box;

        for(int i = 0; i<9; i++) {
            for (int j = 0; j<9; j++) {
                char num = board[i][j];
                if (num == '.') continue; // Skip empty cells
                int boxIndex = (i / 3) * 3 + (j/ 3) + 1; // 0-based index for boxes

                // Check if num already exists in the row, column, or box
                if (entries_row[i].count(num) || entries_col[j].count(num) || entries_box[boxIndex].count(num)) {
                    return false;
                }

                // Mark num as seen in row, column, and box
                entries_row[i].insert(num);
                entries_col[j].insert(num);
                entries_box[boxIndex].insert(num);
            }
        }

        return true;
    }

    void printMap(const unordered_map<int, unordered_set<char>>& mp, string name) {
        cout << name << ":\n";
        for (const auto& row : mp) {
            cout << "Index " << row.first << " -> { ";
            for (const auto& num : row.second) {
                cout << num << " ";
            }
            cout << "}\n";
        }
        cout << "----------------------\n";
    }

    bool brute_force(vector<vector<char>>& board) {
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