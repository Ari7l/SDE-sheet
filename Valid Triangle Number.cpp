class Solution {
public:
    // this problem is similar to 3SUM 
    //to form a valid triangle sum of two sides must be greater than the 3rd side
    //first we sort the array we fix a side in this case it is 'k' and we check for all the sides whose sum can be >nums[k]
    //we can also traverse left to right if we want
    //count+=j-i WHY?
    //   i                  j   k
//      [3, 19, 22, 24, 35, 82, 84]
    //if for above configuration (nums[i]+nums[j]>nums[k]) then we know that all the elements to right of 3 are also >(sorted array)
    //hence we can say that they are also valid pair hence j-i;
    //similarly for all pairs, now if above condition is not true, i++ why, bcoz we want sum greater than nums[k] and we know array 
    // is sorted hence i++
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count =0 ;
        int n = nums.size();
        for(int k=n-1 ;k>1 ;k--){
            int i = 0 , j=k-1;
            while(i<j){
                if(nums[i]+nums[j]>nums[k]){
                    count+=j-i;
                    j--;
                }
                else{
                    i++;
                }
            }
        }
        return count;
    }
};