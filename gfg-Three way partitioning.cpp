class Solution{   
public:
    //Function to partition the array around the range such 
    //that arrayay is divided into three parts.
    //IN this function we are only checking if the current ele is smaller than 
    //left range a or greater than right range b and
    // if the ele is between a and b then we will leave at that place
    void threeWayPartition(vector<int>& array,int a, int b)
    {
         int start = 0 ,end = array.size()-1;
     for(int i=0; i<=end;){
         //if i crosses the end ele it is done
         if(array[i]<a){
             //if the arr[i]<a then we will initilize the start at a element 
             //just greater than arr[i] which is the correct place for a
             swap(array[start++],array[i++]);
         }
         else if(array[i]>b){
             //if the arr[i] is > b then swap the ele with the right most ele
             //decrement end pointer hence all ele >b will be on right side
             swap(array[end--],array[i]);
         }
         else{
             i++;
         }
     }
        // code here 
    }
};
//Time Complexity: O(n)
// Auxiliary Space: O(1)
