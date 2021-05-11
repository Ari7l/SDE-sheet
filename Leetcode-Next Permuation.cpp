  
class Solution {
public:

    void swap(vector<int>& nums,int i,int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void reverse(vector<int>& nums,int start,int end){
        while(start<end){
            swap(nums,start,end);
            start++; end--;
        }
        return;
        
    }
    void nextPermutation(vector<int>& nums) {
        int n= nums.size();
        if(n<2) return ;
        int index =n-1; // starting from last element find largest index i
        while(index>0){ // such that nums[i-1]<nums[i]
            if(nums[index-1]<nums[index]) break;
            index--;
        }
        if(index==0){ // if the input is in descending order its the largest permutation
            reverse(nums,0,n-1);// hence just reverse the array and return 
            return;
        }
        else{
            int val = nums[index-1];// element to be swapped
            int j=n-1;
            while(j>=index){
                if(nums[j]>val) break;
                j--;
            }
            swap(nums,j,index-1);
            reverse(nums,index,n-1);
        }
    }
}; // time complexity O(n) and space complexity O(1)