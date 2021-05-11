class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
         unordered_map<int,int>mp; // unordered_map operation O(1) and mp operation O(logn)
        int Pairs =0;
        for(int i=0;i<n;++i) mp[arr[i]]++; // conunting the frequency of each element
        for(int i=0;i<n;++i){
            int rem = k - arr[i]; 
            Pairs+=mp[rem]; // if there is a element in array such that their sum == k then increment the count
            if(rem==arr[i])Pairs--;//(1,2) and (2,1) are same hence decrement count
        }
        return Pairs/2; // ew have counted the frequeceny twice hence take the half 
    }
};
//TIME : O(N)
// SPPACE : O(N)
