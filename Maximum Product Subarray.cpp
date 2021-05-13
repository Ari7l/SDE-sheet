//Maximum Product Subarray
int maxProduct(int A[], int n) {
    // store the result that is the max we have found so far
    int maxSoFar = A[0];
    int imax = A[0];
    int imin = A[0];
    // imax/imin stores the max/min product of
    //imax and imin are seperated as multiplication with negative number is tricky
    // subarray that ends with the current number A[i]
    for (int i = 1; i < n; i++) {
        // when we bigger/postive number is multiplied by negative/smaller number it becomes small/negaive
        //while negative/smaller number multiplied by negative/smaller number becomes bigger
        // hence we are swapping the imax and imin
        if (A[i] < 0)
            swap(imax, imin);

        // max/min product for the current number is either the current number itself
        // or the max/min by the previous number times the current one
        // if A[i]==0 then subarray starts from the number after the zero ans imax and imin become zero
        imax = max(A[i], imax * A[i]);
        imin = min(A[i], imin * A[i]);

        // the newly computed max value is a candidate for our global result
        maxSoFar = max(maxSoFar, imax);
    }
    return maxSoFar;
}
//TIME:O(N)
//SPACE:O(1)