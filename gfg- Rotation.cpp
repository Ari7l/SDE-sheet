class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    //bascially we have to find the index of the min element
	     int low = 0 ;
	     int high = n-1;
	     if(arr[low]<arr[high]) return 0;
	     while(low<=high){
	         int mid = low + high -low/2 ;
	         int next = (mid+1)%n ; //if mid is last ele then it will come back to first ele after modulo
	         //if n =8 and mid = 7 then next will become 0;
	         int prev = (mid + n-1)%n;//same here if mid=0 then prev = 7
	         if(arr[mid]<=arr[next] && arr[mid]<=arr[prev]){
	             //if mid is minimum ele then its smalller then it right ans left element
	             return mid;
	         }
	         else if(arr[low]<=arr[mid]){
	             //if this condtion is true it means right of array is unsorted hecnce we will
	             //find the answer there and viceversa
	             low = mid +1;
	         }
	         else{
	             high = mid-1;
	         }
	     }

	}

    int findKRotation(int arr[], int n) {
	    //bascially we have to find the index of the min element
	     int lo = 0 ;
	     int hi = n-1;
	     if(arr[lo]<arr[hi]) return 0;
	      while(lo<hi){
            int mid=(lo+hi)/2;
            if(arr[mid]>arr[hi]) lo=mid+1;
            else hi=mid;
        }
        return lo;

	}
//Expected Time Complexity: O(log(N))
//Expected Auxiliary Space: O(1)
};
