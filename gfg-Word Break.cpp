unordered_map<string,int>dp;
int  dict(string s,vector<string> &B){
    int size = s.size();
    if(size==0) return 1; //if whole string is searched
    if(dp[s]!=0) return dp[s]; //if value is already calculated return it
    for(int i=1 ;i<=size;++i){
        int f=0;
        string ss = s.substr(0,i); //check if the prefix exits in the dictionary
        for(int j=0 ;j<B.size();++j){
            if(ss.compare(B[j])==0){
                f=1;//prefix exists in the dict
                break;
            }
        }
        //if prefix is present search for the remainig substring in the 
        //dict and if that is also found return 1;
        //e.g A = "abcde" then search 'a' first and if it is found
        //search bcde
        if(f==1 && dict(s.substr(i,size-i),B)==1) return dp[s]=1;
        
    }
    //if any above condition is false return -1;
    return dp[s]=-1;
     
}

int wordBreak(string A, vector<string> &B) {
    //code here
    int ans  = dict(A,B);
    if(ans==1) return 1;
    return 0;
}
//Expected time complexity: O(s2)
//Expected auxiliary space: O(s) , where s = length of string A