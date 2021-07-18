//This is a recersive approach : exponential
class Solution{
public:
    int matrixChain(int arr[], int i ,int j ){
        if(i>=j) return 0 ;// there are N ele hence N-1 matrices
        int ans = INT_MAX;
        for( int k = i ;k<j; ++k){
            //we are adding cost of left half + right half + current operation values
             int cost = matrixChain(arr,i,k) + matrixChain(arr,k+1,j) + (arr[i-1]
                        *arr[k] *arr[j]);
            ans = min(ans, cost);
        }
        return ans;
        
    }
        
    int matrixMultiplication(int N, int arr[])
    {
        return matrixChain(arr , 1 ,N-1);
      
    }
};

//this top - down memoization method

class Solution{
public:
        int dp[100][100] ;     
      int matrixChain(int arr[], int i ,int j ){
        if(i>=j) return 0 ;// there are N ele hence N-1 matrices
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = INT_MAX;
        for( int k = i ;k<j; ++k){
            //we are adding cost of left half + right half + current operation values
              dp[i][j] = matrixChain(arr,i,k) + matrixChain(arr,k+1,j) + (arr[i-1]
                        *arr[k] *arr[j]);
            ans = min(ans, dp[i][j]);
        }
        return dp[i][j]=ans;
      }
    int matrixMultiplication(int N, int arr[])
    {  
         memset(dp,-1,sizeof(dp));
         return matrixChain(arr,1,N-1);
        
    }
};
//
//Expected Time Complexity: O(N3)
//Expected Auxiliary Space: O(N2)