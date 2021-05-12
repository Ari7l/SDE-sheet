//Subarray with 0 sum
class Solution{
    public:
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {  
       unordered_set<int>st; //O(1) operation O(N) space
       int sum =0;
       //The idea is to find the prefix  sum till ith index and check if that sum already exist or 
       // th sum is '0' if either of the condition works the array contains the subarray with sum 0
       // This works because if the prefix sum repeats that means the elements the till next 
       // repeated sum must add upto zero 
       //e.g. 4 2 -3 1 6 
       // sum 4 6  3 4  now 4 repeats it means the elements till next 4 add upto zero 2 -3 1 
       for(int i=0;i<n;++i){
           sum+=arr[i];
           if(st.find(sum)!=st.end()||sum==0){
               return true;
           }
           st.insert(sum);
       }
       return false;
       }
      
      // TIME and SPACE : O(N)  

};
