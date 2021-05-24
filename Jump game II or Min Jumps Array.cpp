int Solution::jump(vector<int> &A) {

    int n =A.size();
    int max_reach = 0;//stores max jumps from the current index
    int last_jump_pos=0;//previous max jump range
    int jumps =0;
    for(int i=0;i<=last_jump_pos; ++i){
       if(i==n-1) return jumps;//if index reaches last index return jumps
       max_reach= max(max_reach ,A[i]+i);//if max_reach for current index is
       //greater than previous then update the max_reach e.g.[2,3,1,1,4]
       //from first index we can go to 1 and 3 ....from 1 we can go to 3 so 
       //max_reach remains same ...from 3 we can go to last index hence update
       if(i==last_jump_pos){
           //once we have come at last index possible then we need one more jump 
           ++jumps;
           last_jump_pos=max_reach;
       }
        
    }
    return -1 ;
}