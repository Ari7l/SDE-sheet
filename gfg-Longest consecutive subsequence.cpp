class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      unordered_set<int>st;// The time complexity of set operations is O(log n) 
      //while for unordered_set, it is O(1)
      int res=1 ;//each element is a increasing subseq.
      for(int i=0 ;i<N;++i) st.insert(arr[i]); //inserting all elements in set
       for(int i=0 ;i<N;++i){
           //e.g [1,2,6,3,5,2,2,1,4]
          // pick a random element each time, and count the elements that you can "go left" and "go right" with
          // so suppose you picked 3 randomly from the hashmap in the example above
          //then check 2 and 4 next. then check 1 and 5 next. then check 6 because 0 doesn't exist in the array.
          //Bam. now you have your answer (right-left-1) 
          int right= arr[i]+1;
          int left = arr[i]-1;
          while(st.find(left)!=st.end()){
              st.erase(left--);
          }
          while(st.find(right)!=st.end()){
              st.erase(right++);
          }
          res = max(res,right-left-1);
          
      }
      return res;
    }
};