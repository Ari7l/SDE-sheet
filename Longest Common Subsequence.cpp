// A = "abbcdgf"
 //B = "bbadcgf"
//o/p = 5
int Solution::solve(string A, string B) {
    int n = A.size();
    int m = B.size();
    int dp[n+1][m+1];
    for(int i=0; i<=n; i++)
	    dp[i][0] = 0;

    for(int i=0; i<=m; i++)
	    dp[0][i] = 0;
    for(int i=1 ;i<=n;++i){
        for(int j=1 ;j<=m;++j){
            //if the two string contains same char increase the max length by 1
            if(A[i-1]==B[j-1]){
            dp[i][j]=1+dp[i-1][j-1];
                }
            else{
                //else update max of previous longest common subseq
               dp[i][j] = max(dp[i-1][j],dp[i][j-1]); 
            }
            
        }
        
    }
    return dp[n][m];
}