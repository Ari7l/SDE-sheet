class NumMatrix {
public:
    vector<vector<int>>aux;
    NumMatrix(vector<vector<int>>& matrix) {
        int rows= matrix.size();
        int cols = matrix[0].size();
        aux.resize(rows+1,vector<int>(1+cols));
        // we are creating a auxillary matrix with one more row and col
        // extra space helps us tackle corner cases such as if any of query contain r1 or c1 as zero
        // also aux[3][3] contains sum of elements from mat[0][0] till mat[2][2]
        
        for(int i=1;i<=rows;++i){
            for(int j=1 ;j<=cols;++j){
                aux[i][j] = matrix[i-1][j-1] + aux[i-1][j] + aux[i][j-1] - aux[i-1][j-1];
                //when aux[i-1][j-1] common in both previous matrix then it needs to subtracted once
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++;//a query like (0,1)->(1,2) in matrix becomes (1,2) ->(2,3) in auxillary matrix
        col1++; //
        row2++;
        col2++;
        return aux[row2][col2]-aux[row1-1][col2]-aux[row2][col1-1]+aux[row1-1][col1-1];
        //when aux[i-1][j-1] common in both previous matrix then it needs to added once
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */