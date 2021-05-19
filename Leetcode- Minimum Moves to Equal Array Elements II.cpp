class Solution {
public:
    // once you sort the array u can observe that the min moves required to make the array equal is 
    //the sum of all the absolute difference between the i th ele and mid ele
    //e.g 1 2 3 4 5  minMoves = 6
    //it is because we can observe that the numbers on the left of the mid are increasing till
    //mid while the numbers from the right are decresing till mid and becoming equal at mid
    int minMoves2(vector<int>& nums) {
        int minMoves = 0;
        sort(nums.begin() ,nums.end());
        int mid = nums.size()/2 ;
        for(int i=0; i<nums.size() ;++i){
            minMoves += abs(nums[i]-nums[mid]);
        }
        return minMoves;
    }
};