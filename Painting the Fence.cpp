class Solution{
    public:
    long long mod = 1000000007;
    long long countWays(int n, int k){
        long dp[n+1] ;
        memset(dp ,0,sizeof dp);
        dp[1]= k;
        dp[2] = k*k;
        for(int i=3 ;i<=n ;++i){
            dp[i] = ((k-1)*(dp[i-1] + dp[i-2]))%mod;

        }
        return dp[n];
    }
};