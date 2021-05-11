long long merge(long long arr[],long long temp[], long long left,long long mid,long long right){
    long long i,j,k;
    long long inv_cnt=0;
    i = left; // first index of left halve array
    j= mid ; // first index of right halve array
    k = left ; // first index of the temp array used for storing sorted array
    while(i<=mid-1 && j<=right){
        if(arr[i]<=arr[j]){// if element in left sorted array is less than right soretd array
            temp[k++]= arr[i++];// we add it to temp array 
        }
        else{
            temp[k++]=arr[j++];
            inv_cnt += mid-i; // if any element in left array is greater than ele in right array then as the left array is sorted
        }                     // all the element on right of current element of left are also greater hence (mid - i) 
                              // gives total inv_cnt  e.g. 2(i) 3 4(mid-1) and 1 inv_cnt = 3 - 0
    }
    while(i<=mid-1){//if right index goes out of bound add remaining ele in left sorted array
        temp[k++]=arr[i++];
    }
    while(j<=right){//if left index goes out of bound add remaining ele in right sorted array
        temp[k++]=arr[j++];
    }
    for(long long m =left ;m<=right;++m){
        arr[m]=temp[m];
    }
    return inv_cnt;
}

 
long long _mergeSort(long long arr[],long long temp[], long long left,long long right){
    long long  mid ,inv_cnt =0;
    if(right>left)// till only one element is remaining
    {
        mid = (right+left)/2;
        inv_cnt += _mergeSort(arr,temp,left,mid);// counting inversion from left subarray
        inv_cnt += _mergeSort(arr,temp,mid+1,right); //counting inversion from right subarray
        
        inv_cnt+=merge(arr,temp,left,mid+1,right);//adding the inversion during the merging of
                                                 // of two halves
    }
    return inv_cnt;
}

// arr[]: Input Array
// N : Size of the Array arr[]
// Function to count inversions in the array.
long long int inversionCount(long long arr[], long long N)
{
    long long temp[N]; // creating temp array to store the sorted array
    return _mergeSort(arr,temp,0,N-1); // calling modified merge sort fun
}
// TIME COMPLEX : O(NlogN)
// SPACE : O(N)