//This is recursive approach 
class Solution {
public:
    vector<vector<int>>memo;
    bool rec(vector<int>& nums, int sum, int pos ,int n ){
        if(sum==0) return 1 ; //if sum becomes zero that means elements add upto sum
        else if(sum < 0 || pos>=n) return 0 ; // out of bounds conditions
        if(memo[pos][sum] !=-1) return memo[pos][sum]; // if values are already calculated return it
        return memo[pos][sum] = ( rec(nums, sum-nums[pos],pos+1,n ) || rec(nums,sum,pos+1,n));//
        // we are either adding the num[pos] into subset or not  sum- nums[pos] represent adding including it
    }
    bool canPartition(vector<int>& nums) {
      int sum = accumulate(nums.begin() ,nums.end() ,0);
      if(sum%2) return false;
      sum= sum/2 ;
        int n = nums.size();
         memo.clear();
        memo.resize(n+1 ,vector<int>(sum+1 ,-1)) ;
        return rec(nums ,sum ,0 ,n);
        
      
    }
};
//dp approach
 bool canPartition(vector<int>& nums) {
      int sum = accumulate(nums.begin() ,nums.end() ,0);
      if(sum%2) return false;
      sum= sum/2 ;
        int n = nums.size();     
     vector<vector<bool>>dp(n+1 ,vector<bool>(sum+1 ,false) );
      dp[0][0] = true ; // sum zero means empty subset hence return true
     for(int i=0 ;i<=n;++i){
         for(int j =0 ;j<=sum ;++j){
             if(i==0) dp[i][j]=false ;// u cant make any sum if there are no elements 
             else if(j==0) dp[i][j]=true ;// if we given any no. of elements and we have to make the sum 0 
             // there is always an empty subset hence true
             else if(nums[i-1]<=j){
                 dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j] ;
                 //if the ele is <= sum then only we can choose to include or exclude
                 //if include it we minus its value from the sum 
                 
             }
             else{
                 dp[i][j] = dp[i-1][j] ;
             }
         }
     }
        return dp[n][sum];
        
    }