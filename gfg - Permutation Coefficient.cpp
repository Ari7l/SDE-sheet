#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//using formula P(n, k) = P(n-1, k) + k* P(n-1, k-1) 
int per(int n, int k){
    int dp[n+1][k+1];
    memset(dp,0,sizeof(dp));

    for(int i = 0; i <=n ;++i){
        for(int j =0; j<=min(i,k) ;++j ){
            if(j==0) dp[i][j] = 1;
            else{
                dp[i][j] = j* dp [i-1][j-1] + dp[i-1][j];
            }
            dp[i][j+1] = 0; // if j becomes greater than i then assign 0
        }
    }
    return dp[n][k];
}
int main() {
    int n , k;
    cin>>n>>k;
    cout<<per(n,k)<<"\n";
}

//TIME and Space: O(n*k);
//O(n)
nt per(int n, int k){
    int fact[n+1];
    memset(fact,0,sizeof(fact));
    fact[0] = 1;
    for(int i = 1; i <=n ;++i){
       fact[i] = i*fact[i-1];
    }
    return fact[n]/fact[n-k];
}