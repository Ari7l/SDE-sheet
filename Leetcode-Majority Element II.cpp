class Solution {
public:
    // this problem is the extension of Moore Majority Vote Algorithm
    // if the majority ele is appering more than n/3 times then there
    // wont be more than two elements at a time in the array
    // hence we will use the algoritm to find the candidate ele

    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int num1 =-1 , count1 =0 ;//num1 is first candidate
        int num2 =-1 ,count2 =0; ////num2 is second candidate
        for(int i=0 ;i<n ;++i){
            if(nums[i]==num1){
                count1++;
            }
            else if(nums[i]==num2){
                count2++;
            }
            else if(count1==0){
                num1 = nums[i];
                count1=1;
            }
            else if(count2==0){
                num2 = nums[i];
                count2=1;
            }
            else{
                count1--;
                count2--;
            }
        }
        vector<int>res;
        int cnt1 =0 ,cnt2=0;
        //following code verify if the potential candidates are the majority ele
        //by counting their frequency
        for(int i=0 ; i<n ;++i){
            if(nums[i]==num1){
                cnt1++;
            }
            else if(nums[i]==num2){
                cnt2++;
            }
           
        }
         if(cnt1>n/3){
                res.push_back(num1);
            }
            if(cnt2>n/3){
                res.push_back(num2);
            }
        return res;
    }
};