class Solution{
    public:
    /*You are required to complete below method */
   
    const int mod = 1000000007;
   
    long long int  countPS(string str)
    {   int n = str.size();
        int dp[n+1][n+1];
        memset(dp,0,sizeof dp);
        for(int i=0 ;i<n;++i) dp[i][i]=1; //all characters of length one are palindrome
        //dp[i][j] represents stores the paindromic subsequences of string starting
        //from  i and ending on j
        //the dp table will be filled in diagonal form in upper triangle part only if the i>j then it will be invalid as starting
        //index cannot be greater than ending index
        for(int l=2 ;l<=n;++l){
           for( int i=0 ;i<n-l+1 ;++i){
               int j = i+l-1;
               if(str[i]==str[j]){
                   //if end charcters match then we will count how many palidromic subseq in suffix and prefix part and add 1 for current
                   //characters that are macthing
                   dp[i][j]=1+dp[i+1][j]+dp[i][j-1];
               }
               else {
                   ////if end charcters dont match then we will count how many palidromic subseq in suffix and prefix part and 
                   //remove the middle part as it will be counted twice in prefix and suffix part
                   dp[i][j] = dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
               }
           }
        }
        return dp[0][n-1]%mod;    }
     
};
//Expected Time Complexity: O(N*N)
//Expected Auxiliary Space: O(N*N)