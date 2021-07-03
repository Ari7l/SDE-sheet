class Solution {
  public:
    int editDistance(string s, string t) {
        // Code here
        int n = s.size() , m= t.size();
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for( int i=0 ; i<=n ;++i){
            for( int j=0 ;j<=m ;++j){
                if(i==0 ) dp[i][j] = j; //if s is empty string
                else if( j==0) dp[i][j] = i; // if t is empty string
                else if(s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j-1]; //if characters match no need  to do anything just take previous value
                else dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i-1][j] ,dp[i][j-1])) ;//else take minimum of 
                //the three opration and add one(cost of operation) 
            }
        }
        return dp[n][m];
    }
};

//Expected Time Complexity: O(|s|*|t|)
//Expected Space Complexity: O(|s|*|t|)