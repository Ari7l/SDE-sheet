//problem asked in Google
//Time Complexity O(NlogN)

bool isPossible(vector<int> &A, int stu ,int limit){
        int pages = 0 ,curr_stu =0;
        for(int i=0 ;i<A.size();++i){
            // if the pages alloted particular student goes over the limit
            //choose next student to allot the books
            if(A[i]+pages>limit){
                curr_stu++;
                pages = A[i];
                if(pages>limit) return false; //if any book has pages>limit 
            }
            else{
                pages += A[i];
            }
            
        }
        if(curr_stu<stu) return true;//books can be alloted successfully to B students
        return false;//we need more than B students to allot all pages without
        //wihout violating the limit 
}
//for binary search, first we have to define search space i.e low and high 
//in this problem, the low is the book with minimum no. of pages(for case if all books have same pages )
// and high is the sum of all the pages(for case if there is only one student)

int Solution::books(vector<int> &A, int B) {
    if(B > A.size()) return -1; //if no. of students is greater than books
    int low = A[0] ;
    int high = 0;
    int res =-1;
    for(int i = 0;i<A.size();i++) {
        high = high + A[i]; 
        low = min(low, A[i]); 
    }
    // we know that our ans is going to lie in between high and low
    while(low<=high){
        int mid = (low +high)/2;
        //we will consider mid as our res and verify by using the isPossible() if it is true, it means
        //mid is one of the possible answer but we want the minimum max pages alloted hence we will
        //decrease the high range
        if(isPossible(A,B,mid)){
            res = mid;
             high = mid-1;
        }
        //if the mid is not our answer it means we need increase our range as we will need more than B
        //no. of stuents to allocate the books which is invalid
        else{
            low = mid+1;
        }
        
    }
    return res;
    //we can also return low 
}
