class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0 ;
        int high = nums.size()-1;
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target){
                ans = mid;
                break;
            }
            else if(nums[mid]>=nums[low]){
                //if left half of array is sorted then we are checking if our elements can exist there
                //4,5,6,7,0,1,2 e.g target = 0 does not follow 
                // 4<=0 && 0<=7 hence we say it must exist in right half
                if(target<=nums[mid] && target>=nums[low]) high = mid -1;
                else low = mid+1;
            }
            else{
                if(target>=nums[mid] && target<=nums[high]) low = mid+1;
                else high = mid -1 ;
            }
        }
        return ans;
    }
};
//time O(logn)