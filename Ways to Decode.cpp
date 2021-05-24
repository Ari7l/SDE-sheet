int Solution::numDecodings(string A) {
    long long mod = 1000000007;
    int  n =A.size();
    long long dp[A.size()+1];
    memset(dp,0,sizeof(dp));
    //only one way to decode a null string
    dp[0]=1;
    //if the first character is not '0' then one way to decode it 012 has zero ways
    //but 102 can be decoded
    dp[1]= (A[0]=='0')?0:1;
    for(int i=2 ;i<=n ;++i){
        // extract the last one digit and  check
        long long oneDigit = stoi(A.substr(i-1,1));
        //extract last two digits and check
        long long twoDigit = stoi(A.substr(i-2,2));
        //if last digit is greater than one then we can decode it
        if(oneDigit>=1){
            dp[i]=(dp[i]%mod + dp[i-1]%mod)%mod;
        }
        //if last two digits is greater than 9 and <=26 then we can decode it
        if(twoDigit>=10 and twoDigit<=26){
            dp[i]=(dp[i]%mod + dp[i-2]%mod)%mod;
        }
        
    }
    return dp[n]%mod;
}
