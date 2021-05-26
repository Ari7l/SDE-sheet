//Brute force way to solve this problem is to generate 2^N subsets by choosing a ele 
//or not and then check for the subset having their sum of weights less than W and having
//maximum value

//1st Approch 
//Expected Time Complexity: O(N*W)
//Expected Auxiliary Space: O(N*W)
//using a 2D dp array 

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       int dp[n+1][W+1];
       for(int i = 0 ;i<=n;++i){
           for(int j=0 ;j<=W;++j){
               if(i==0||j==0) dp[i][j]=0;
               else if(j>=wt[i-1]){
                   dp[i][j] = max(dp[i-1][j-wt[i-1]]+val[i-1] , dp[i-1][j]);
               }
               else{
                   dp[i][j]=dp[i-1][j];
               }
           }
       }
       return dp[n][W];
    }
};

//2nd approach
//Expected Time Complexity: O(N*W)
//Expected Auxiliary Space: O(W)
//using 2D array with only two rows dp[2][W]
//from 1st approch we now know the current max value only depend upon the previous row i.e.
// you can see that dp[i][j] only depends on previous row, so you can optimize the space by only 
//using 2 rows instead of the matrix. Let's say dp[0][j] and dp[1][j]. 
//Every time you finish updating dp[1][j], dp[0][j] have no value,
// you can copy dp[1][j] to dp[0][j] as the previous row of the next new row
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       int dp[2][W+1];
       memset(dp,0,sizeof(dp));
       int i=0;
       //we are checking iterating through each element
       while(i<n){
           int j =0;
           //if i is odd index that means we have odd no. of elements then
           //we will update the dp[1][W]
           if(i%2!=0){
               //if the capacity is greater than the weight then only we can
               //include the element
               while(j++<=W){
                   //include element
                   if(j>=wt[i]){
                       dp[1][j] = max(dp[0][j] , val[i]+dp[0][j-wt[i]]);
                   }
                   //exclude element
                   else{
                       dp[1][j]=dp[0][j];
                   }
               }
           }
           else{
                //if i is even index that means we have even no. of elements then
                 //we will update the dp[0][W]
                while(j++<=W){
                   if(j>=wt[i]){
                       dp[0][j] = max(dp[1][j] , val[i]+dp[1][j-wt[i]]);
                   }
                   else{
                       dp[0][j]=dp[1][j];
                   }
               }
           }
           i++;
           
       }
       //if n is odd then answer is lies in 0th row as it was the last row
       //that was updated
       return (n%2!=0)?dp[0][W]:dp[1][W];
    }
};

//3rd approach
//Expected Time Complexity: O(N*W)
//Expected Auxiliary Space: O(W)
//using 1D array dp[W]
//first we are iterate through each element as in 2D array then we are iterating from right
//to left becoz we know that the current value will depend upon the dp[i-wt[i]] so if we update from
// left to right the previous state will be updated and we wont have correct result
//if you update array backwards, all dependencies are not touched!
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
      
      int dp[W+1];
      memset(dp, 0,sizeof(dp));
       for(int i = 0 ;i<n;++i){
           for(int j=W ;j>=W;j--){
                dp[j] = max(dp[j],val[i]+dp[j-wt[i]]);
           }
       }
       return dp[W];
    }
};
