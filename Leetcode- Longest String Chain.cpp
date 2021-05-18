class Solution {
public:
    static bool compare(string &s1 ,string &s2){
        return s1.length()<s2.length();
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),compare);// sorting the vector by length of string
        int res =0;
        
        unordered_map<string,int>dp; //stores the longest chain formed using the current word like dp
        for(auto w : words){
            // we are going to iterate through each string in the vector and delete a character from 
            // the string and check if there is any predecessor of the current string exists in the map
            // if it does exists then we will increase the res by one and if not then we will keep it 1
            //becoz longest chain can be 1 by default
            for(int i=0 ; i<w.length() ;++i){
                string pred = w.substr(0,i) + w.substr(i+1); //delete each character and check for 
                // predecessor
                int check ;
                if(dp.find(pred)==dp.end()){ // if pred not found
                    check=1;
                }
                else{// pred is present increase length by 1
                    check = 1 + dp[pred];
                    
                }
                dp[w] = max(dp[w],check);
            }
            res = max(res,dp[w]) ;//taking longest chain 
            
            
        }
        return res;
    }
};
//1 <= words.length <= 1000
//1 <= words[i].length <= 16