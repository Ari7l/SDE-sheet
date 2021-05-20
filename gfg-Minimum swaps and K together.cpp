//Minimum swaps and K together
//we have to group all the ele less than k together using mini swaps
//hence we will be using the sliding window tech
int minSwap(int *arr, int n, int k) {
    int ans=0;
    int cnt= 0;
    //first count all ele <= K
    for(int i=0 ;i<n ;++i){
        if(arr[i]<=k) cnt++;
    }
    int curr =0; 
    //we are storing all the ele in first window >k in curr
    for (int i = 0; i < cnt; ++i){
        if (arr[i] > k) ++curr;
            
    }
    ans=curr; 
    //now we are going to check every window for all the ele>k and update the
    //minimum as ans
    for(int i=0,j=cnt ;j<n;++i,++j){
        // decrement curr for previous window
        if(arr[i]>k)--curr;
        //increment curr for previous window
        if(arr[j]>k)++curr;
        //taking min of all window
        ans = min(ans,curr);
    }
    return ans;
    
        
    }
