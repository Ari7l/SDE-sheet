#define mod 1000000007
// C(n, k) = C(n-1, k-1) + C(n-1, k)
//   C(n, 0) = C(n, n) = 1
class Solution{
public:

    int nCr(int n, int r){
        if(n==r || r==0) return 1;
        if(r>n) return 0;
        int dp[r+1];
        
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1; i<=n ;++i ){
            for(int j=min(n,r) ;j>=0 ;--j){
                dp[j] = (dp[j]%mod + dp[j-1]%mod)%mod;
            }
        }
        return dp[r]%mod;
        
    }
};