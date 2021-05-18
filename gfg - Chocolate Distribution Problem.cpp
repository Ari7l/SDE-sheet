class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(), a.end());
     long long minDiff = INT_MAX;
     //we are using the sliding window tech. first we sort the vector
     // for each window of size m we will calculate the minDiff between the maxChoclate
     // and minChoclate for that window and then take the minimum of all such window
     for(long long i=0 ;i<n-m+1;++i){
         
         if(n<m) return -1;
         long long diff = a[i+m-1] - a[i];
         minDiff = min(minDiff,diff);
         
     }
     return minDiff;
    
    }   
};
// time: O(N*Log(N))
//Space: O(1)