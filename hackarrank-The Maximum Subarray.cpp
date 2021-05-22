// we have to return maximum subarray sum as well as maximum subsequences sum
vector<int> maxSubarray(vector<int> arr) {
        vector<int>res;
        int n= arr.size();
        //we are initilizing all the variables with first ele as The subarray and subsequences
        // you consider should have at least one element.
        //hence even if the all the element all negative return the least one e.g. -2 -3 -1 -4 -6 ans: -1 -1


        int maxHere = arr[0] ,maxSoFar=arr[0];
        int Curr_sum = arr[0] ,MaxSub = arr[0];
        for(int i=1 ;i<n; ++i){
            maxHere+=arr[i];
            if(arr[i]>maxHere){
                maxHere = arr[i];
            }
            maxSoFar = max(maxSoFar,maxHere);
            Curr_sum+=arr[i];
            if(arr[i]>Curr_sum){
                Curr_sum = arr[i];
            }
            //Maxsub check if the curr_sum is greater than the previous sum and if it is
            //MaxSub is updated
            MaxSub = max(MaxSub,Curr_sum);
            Curr_sum=MaxSub;//We want to add the new element to maximum subseq. sum 
        }
        res.push_back(maxSoFar);
        res.push_back(MaxSub);
        return res;
}