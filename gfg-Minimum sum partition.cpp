class Solution{

  public:
     void subsetSum(int n, int sum,int arr[],vector<int>&subSet){
         int dp[n+1][sum+1];
         memset(dp,0,sizeof dp);
         dp[0][0]=1;
         for(int i=1;i<=n;++i){
             dp[0][i] = 0;
         }
         for(int i=1;i<=n;++i){
             dp[i][0] = 1;
         }
         for(int i=1 ;i<=n;++i){
             for(int j=1;j<=sum;++j){
                 if(arr[i-1]<=j){
                     dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                 }
                 else{
                     dp[i][j] = dp[i-1][j];
                 }
                 
             }
         }
         for(int i=0;i<=sum/2;++i){
             if(dp[n][i]){
                 subSet.push_back(i);
             }
         }
         return;
         
     }
  
	int minDifference(int arr[], int n)  { 
	    int sum = 0;
	    for(int i=0 ;i<n;++i) sum+=arr[i];
	    vector<int>subSet;
	    subsetSum(n,sum,arr,subSet);
	    int mini = INT_MAX;
	    for(int i=0;i<subSet.size();++i){
	        mini = min(mini ,sum - 2*subSet[i]);
	    }
	    return mini;
	} 
};
//Expected Time Complexity: O(N*|sum of array elements|)
//Expected Auxiliary Space: O(N*|sum of array elements|)