//Rearrange array in alternating positive & negative items with O(1) extra space(without using extra space)
//Naive Approch : this solution doesn't maintain original order of elements
// e.g input  {-2, 3, 4, -1} output: {-2, 3, -1, 4} OR {-1, 3, -2, 4}
// we are going to use two pointer i and j to rearrange the positive ele on left side of array and - ele on right side 
// then swap the every other positive with negative element
void rearrange(int arr[], int n){
	int i = -1 ,j=n;
	while(i<j){
		while(i<=n-1 && arr[i]>0){// loop runs till we encounter negative element
			i++;
		}
		while(j>=0 && arr[j]<0){ // loop runs till we encounter positive element
			j--;
		}
		if(i<j){ // once we reach elements at wrong position we will swap them
			swap(arr[i],arr[j]);
		}
	}
	if(i==0 || i==n) return ;
	int k=0; //we are starting from first index that is +ve ele and index i is already at first -Ve ele
	while(k<n && i<n){
		swap(arr[k],swap[i]);
		k +=2;// move k by 2 pos ans i by 1 pos then swap
		i +=1;
	}

}
TIME : O(N)
SPACE : O(1)
