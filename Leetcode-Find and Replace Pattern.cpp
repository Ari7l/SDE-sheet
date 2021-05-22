class Solution {
public:
    //we are converting/mapping the string into a generalized pattern hence it will be easy to compare
    //Consider the words "mmnpoq" and "ppqqqz". We can convert these into - "aabcde" and "aabbbc". Since        they are not equal, we can say both these words don't match.
    //Similarly, the words "mnpqrr" and "xyzabb" can be converted into "abcdee" and "abcdee" respectively.      Since they are equal, we say that these two words match.
    string convert(string w1){
        unordered_map<char,char>mp;
        char c = 'a';
        for(auto ch:w1){
            //unordered_map does not allow duplicate keys hence if the char of w1 is already mapped
            //count() will return 1 else 0 once 
            
            if(!mp.count(ch)){
                mp[ch]=c;
                c++;//once 'a' is mapped to a chara we move to 'b' 
            }
        }
        for(auto &ch:w1){
            ch = mp[ch];//we are converting the original string to generalized string
        }
        return w1;
        
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string>res;
        string p = convert(pattern);
        for(auto &w :words){
            if(p==convert(w)) res.push_back(w);
        }
        return res;
    }
};
//Time Complexity: O(N * M) where N is the length of words and M is the length of each word/pattern
//Space Complexity: O(M) for the codex
//or O(N + M) if you count the space of the output (res)
