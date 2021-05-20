class Solution{
    public:
    int closest3Sum(int A[], int N, int X)
    {   sort(A,A+N);

        int minSum = A[0]+A[1]+A[N-1]; // we can take any three elements initially
        for(int i=0;i<N-2;++i){ 
            int j=i+1 ,k=N-1;
            while(j<k){
              int sum = A[i]+A[j]+A[k];
              //if sum is less than X we increase it by j++ as array is sorted
              if(sum<X) j++;
               //if sum is greater than X we decrease it by k-- as array is sorted
              else k--;
              // at each itreation we check if the difference between the sum and X 
              // is minimum if it is less replace with minSum
              if(abs(sum - X)<abs(minSum-X)){
                  minSum = sum;
              }
            }
        }
        return minSum;
        // code here
    }
};
//TIME O(N*2)
//SPACE O(1)
