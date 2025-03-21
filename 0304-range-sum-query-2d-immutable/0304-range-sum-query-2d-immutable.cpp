class NumMatrix {
public:

    const static int M = 300;
    static int pf[M][M];
    NumMatrix(vector<vector<int>>& matrix) {
        for (int i = 1; i<=matrix.size(); i++) {
            for (int j = 1; j<=matrix[0].size(); j++) {
                pf[i][j] = matrix[i-1][j-1] + pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1];
            }
        }
    }
    
    // 0 Based
    int sumRegion(int row1, int col1, int row2, int col2) {
        return pf[row2+1][col2+1] - pf[row2+1][col1] - pf[row1][col2+1] + pf[row1][col1];
    }
};

// **Define the static array outside the class**
int NumMatrix::pf[NumMatrix::M][NumMatrix::M] = {{0}};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */