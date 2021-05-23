 // Bottom-up approach
    // TC: O(N*N), SC: O(N*N)

int Solution::solve(string A) {
    int n = A.size();
    int dp[n][n]={0};
    // all single chars are palindromic
    for(int i=0 ;i<n ;++i){
        dp[i][i]=1;
        
    }
    //starting from string of len =2 to n check all the palindrome seq. of len=i;
        for(int len = 2;len<=n ;++len){
            
            for(int i=0 ;i<n-len+1; ++i){
                int j = i+len -1;
                 // if the chars are same, then that contributes 2, otherwise since
                // individually they are palindromic so max length 1
                if(A[i]==A[j] and len==2){
                    dp[i][j]=2;
                }
                // for s[i:j]:
                    // longest palindrome length in s[i+1 : j-1] and +1 if s[i] == s[j]
                    // if s[i] != s[j],
                    //longest length palindrome = Max of longest palin in s[i:j-1] and s[i+1:j]
                else if(A[i]==A[j]){
                    dp[i][j] = 2+dp[i+1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
    
    return dp[0][n-1];
    
}
//