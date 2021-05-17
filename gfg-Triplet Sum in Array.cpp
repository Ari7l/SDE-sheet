class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        sort(A,A+n);
        bool flag = false;
    for(int i=0 ;i<n;++i){
        int rem = X - A[i];
        int j=i+1 ,k=n-1;
        while(j<k){
            if(A[j]+A[k]==rem){
                flag=true;
                return flag;
            }
            else if(A[j]+A[k]<rem){ //if the sum = A[j]+A[k] is < remainder it means
            //we have to increase the sum hence j++ as array is sorted 
                j++;
            }
            else{//if the sum = A[j]+A[k] is > remainder it means
            //we have to decrease the sum hence k-- as array is sorted 
                k--;
            }
             
        }
    }
    return flag;
        //Your Code Here
    }

};
//TIME : O(N*2)
// SPACE : O(1)