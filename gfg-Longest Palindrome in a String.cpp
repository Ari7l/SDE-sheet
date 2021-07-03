class Solution {
  
  public:
  
    int start , maxLen;
    void expandAroundCenter(string S, int j ,int k){
        while(j>=0 && k<S.size() && S[j]==S[k]){
            j--;
            k++;
        }
        if(maxLen < k-j-1){
            start = j+1;
            maxLen = k-j-1;
            }
        
    }
    string longestPalin(string S) {
       int n = S.size();
       for(int i=0 ;i<n-1;++i){
           expandAroundCenter(S,i,i); //checking for odd length palindrome,mostly start
           //on single character
           expandAroundCenter(S,i,i+1);//checking for even length palindrome
       }
       
       return S.substr(start,maxLen);
    }
};
// Expected Time Complexity: O(|S|2).
//Expected Auxiliary Space: O(1).