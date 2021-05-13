 //Majority element I - Moore Majority Vote Algorithm
// in this problem we know that the candidate element(a random element which can be a majority ele)
// is the majority element as we can assume it always exist
// orelse we have to verify if the candidate element is actually the majority element
// First we assume first ele as majority ele and take count=1
//and scan the vector if find the majority (same ele) ele we can increment the count
// or else we decrement the count, if the count hits zero at index i we assume the that to majority ele
//initilize the count as 1 again
//WHY this works:
//the occurance of majority ele is > n/2 while all the other elements combined occurance
// is less than <n/2 e.g. 2 2 2 4 3 
//initially count goes to count = 3 now when we come at 4 and 3 the count will decrement but never hit zero
// hence the 2 remain majority element
class Solution {
public:
    int findCandidate(vector<int>& nums,int n){
        int majority_index =0 , count =1 ;
        for(int i=1 ;i<n ;++i){
            if(nums[majority_index]==nums[i]){
                count++;
            }
            else{
                count--;
            }
            if(count==0){
                majority_index = i;
                count=1;
            }
        }
        return nums[majority_index];
    }
 
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cand = findCandidate(nums,n);
        return cand;
        
    }
};
//TIME:O(N)
//SPACE:O(1)