class Solution {
public:
    bool isVaild(int row, int col,vector<vector<int >>&board ){
        //all the queens are placed on different row from top to bottom hence
        // checking the rows above current row is sufficient
        for(int r = row-1 ;r>=0 ;--r){
                if(board[r][col]==1)return false; 
        }
         // check bottom right to top left diagonal for queens
        for(int r = row-1 , c =col-1 ;r>=0 && c>=0;r--,c--){
            if(board[r][c]==1) return false;
        }
        //check for bottom left to top right diagonal
        for(int r=row-1 ,c = col +1 ;r>=0 && c<board[0].size();r--,c++){
             if(board[r][c]==1) return false;
        }
        return true;
    }
    int totalSol(int curr_row ,vector<vector<int >>&board){
        //if we reach th last nth row then we have found a arrangement return 1;
        if(curr_row==board.size()) return 1;
        int count= 0;
        for(int col =0 ;col<board[curr_row].size();++col){
            // found an empty space where we can possible place a queen
            if(board[curr_row][col]==0){
                 if(isVaild(curr_row,col,board)){
                      // 1 signifies a queen is here
                     board[curr_row][col]=1;
                      // backtrack to find another possible good state
                     count+=totalSol(curr_row+1 , board);
                     board[curr_row][col]=0;
                 }
            }
            
        }
        return count;
        
    }
    
    int totalNQueens(int n) {
        vector<vector<int >>board(n,vector<int>(n,0));
        int ans = totalSol(0,board); 
        return ans;
    }
};