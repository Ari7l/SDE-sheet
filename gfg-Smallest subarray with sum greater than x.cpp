class Solution{
  public:
    //we are using the prefix sum 
    int sb(int arr[], int n, int x)
    {   
        int curr_sum=0 ,minLen = n+1 ;
        int start =0 ,end = 0;
        while(end<n){
            // add to the prefix sum till it is smaller than x
            while(end<n && curr_sum<=x){
                curr_sum+=arr[end++];
            }
            //once the curr_sum becomes better than x we start subtracting 
            //arr ele from start till the curr_sum is just greater than x
            //calculate the mini. length by taking the diff in two pointers
            while(start<n && curr_sum>x){
                if(end-start<minLen){
                    minLen = end - start ;
                }
                curr_sum-=arr[start];
                start++;
            }
        }
        
         return minLen;   
        }
        
        // Your code goes here   
};
// time: O(N)
//Space: O(1)