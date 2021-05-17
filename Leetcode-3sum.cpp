class Solution {
public:
    // an integer array nums, return all the triplets such that nums[i] + nums[j] + nums[k] == 0
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0 ;i<n;++i){
            //array is sorted hence if nums[i]>0 then sum will never be 0.
            if(nums[i]>0){
                break;
            }
            if(i>0 && nums[i]==nums[i-1]) continue;//skip repeat  duplicate triplets
            int target = 0 - nums[i];
            int j=i+1 ,k=n-1;
            while(j<k){
                if(nums[j]+nums[k]==target){
                    res.push_back({nums[i],nums[j],nums[k]});
                    j++;k--;
                    while(j<k && nums[j-1]==nums[j]) j++;//if the current element is same as 
                    // last element then skip it to avoid duplcate
                    //2 2 3
                  //j-1 j then increment j to 3
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
                else if(nums[j]+nums[k]<target){ //if the sum = nums[j]+nums[k] is < remainder it  means
                //we have to increase the sum hence j++ as array is sorted 
                    j++;
                }
                else{//if the sum = nums[j]+nums[k] is > remainder it means
                //we have to decrease the sum hence k-- as array is sorted 
                    k--;
                }
             
        }
    }
        return res;
}
};
// TIME : O(N*2)