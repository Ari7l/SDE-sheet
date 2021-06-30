class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    int n = str.size();
    int dp[n+1][n+1];
    for(int i=0; i<=n; i++)
	    dp[i][0] = 0;

    for(int i=0; i<=n; i++)
	    dp[0][i] = 0;
    for(int i=1 ;i<=n;++i){
        for(int j=1 ;j<=n;++j){
            //if the two string contains same char increase the max length by 1 
            //and if they dont have the same index in the original string 
            if(str[i-1]==str[j-1] && i!=j){
            dp[i][j]=1+dp[i-1][j-1];
                }
            else{
                //else update max of previous longest common subseq
               dp[i][j] = max(dp[i-1][j],dp[i][j-1]); 
            }
            
        }
        
    }
    return dp[n][n];
		}

};
//Expected Time Complexity: O(n2)
//Expected Space Complexity: O(n2)