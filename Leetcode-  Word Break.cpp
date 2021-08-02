class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
         unordered_set<string>st(wordDict.begin() ,wordDict.end());
          vector<bool> dp(n+1,false);
        //dp[i] is true is if the string ending at index i  is valid string i.e it exists in the dictionary 
          dp[0]=true ; //bcoz empty string can be formed with any word in dict
          for(int i=1;i<=n ;++i){
              //we are checking for if any of the substring of s ending at i is present in the dict 
              for(int j=i-1 ;j>=0 ;--j){
                  if(dp[j]){
                      string str = s.substr(j ,i-j) ;
                      if(st.find(str) !=st.end()){
                          dp[i] = true;
                          break;
                      }
                  }
              }
              
              
          }
        
        return dp[n];
    }
};