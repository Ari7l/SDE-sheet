
int dp[1000][1000][2],c;
string a, b;
int fun(int i, int j, int rotated)
{
    if(i>j)
        return 0;
    if(i==j)
    {
        if(a[i]==b[i])
            return 0;
        return 1;
    }
    if(dp[i][j][rotated]>=0)
        return dp[i][j][rotated];
    int ans = 100000;
    if(rotated==1)
    {
        return dp[i][j][1] = ((a[j]!=b[i]) + (a[i]!=b[j]) + fun(i+1, j-1, 1)); 
    }
    ans = min(ans, c + (a[i]!=b[j]) + (a[j]!=b[i])+ fun(i+1, j-1, 1));
    ans = min(ans, (a[i]!=b[i]) + fun(i+1, j, 0) );
    ans = min(ans, (a[j]!=b[j]) + fun(i, j-1, 0) );
    return dp[i][j][0] = ans;
}

int Solution::solve(string A, string B, int C) {
    int n = A.length();
    a = A;
    b = B;
    c = C;
    memset(dp, -1, sizeof dp);
    int ans = fun(0,n-1,0);
    return ans;
}



//shorter code using inline fuction
int Solution::solve(string A, string B, int C) {
     int m = A.size();
    int n = B.size();
    vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(2,-1))); //3d vector 
    //inline generalized lambda function
    //template<typename T>
    //[](T a, T b) -> T { return a + b };
    function<int(int,int,bool)>go =[&](int l,int r, bool rotated=false)->int{
        if(l>r) return 0 ; //invalid case
        if(l==r) return A[l]!=B[r];//if on same charc check if they are same
        auto &ans = dp[l][r][rotated];// we can also return dp[l][r][roated] directly but for convinence 
        //ans is to be modified hence it passed by reference
        if(ans!=-1) return ans;
        if(rotated){
        //if we reverse the string we need first char of A with last char of B and viceversa
        //recursion says i rotated the string and checking the first and last char of both strings now
        //go and check the all char between them
         return ans = (A[l]!=B[r]) + (A[r]!=B[l]) + go(l+1,r-1,1);
        }
        else{
            //check first char of A with first char of B
            ans = (A[l]!=B[l]) + go(l+1,r,0);
            //check last char of A with last char of B
            ans = min(ans, (A[r]!=B[r]) + go(l,r-1,0));
            //check after rotating the string
            ans = min(ans,C+go(l,r,1));
            
        }
        return ans;
    };
    return go(0,m-1,0);
}
// Time and Space complexity is O(N*N*2)