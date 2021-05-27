class Solution {
public:
    
    // return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common            letters.
    //Now to element the strings with common elements we are using the frequency map i.e.freq 
    //for each string in words we are storing the occurance of all the letters 
    //after that we till ith index we will check if the any of the string before that have common letters
    //if they dont have common letters we just take the product of their length
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<vector<bool>>v;
        for(auto word:words){
            vector<bool>freq(26,false);
            for(auto &ch:word){
                freq[ch - 'a'] = true;
            }
            v.push_back(freq);
        }
        int ans =0 , k;
        for(int i=0 ;i<n ;++i){
            for(int j=0 ;j<i ;++j){
                for( k =0 ;k<26 ;++k){
                    if(v[i][k] && v[j][k]) break;
                   
                }
                 if(k==26){
                        ans = max(ans ,(int)words[i].size()*(int)words[j].size());
                    }
                
            }
            
        }
        return ans;
        
        
        
    }
};
//Time Complexity : O(n*(N+n)), where n is the length of words and N is the average length of words
//Space Complexity : O(n)
//We can also use bitset 
 int maxProduct(vector<string>& words) {
        int n = words.size();
         int ans =0 ,k;
        vector<bitset<26>>v(n);
        for(int i=0 ;i<n ;++i){
            for(auto &ch:words[i]){
                v[i][ch-'a'] = 1;
            }
            
               for(int j=0 ;j<i ;++j){
                   for( k =0 ;k<26 ;++k){
                    if(v[i][k] && v[j][k]) break;
                        }
                   
                   if(k==26){
                        ans = max(ans ,(int)words[i].size()*(int)words[j].size());
                    }
                
            }
            
        }
        
        return ans;
        
        
        
    }
    