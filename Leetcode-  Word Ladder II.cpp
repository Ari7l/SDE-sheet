class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>>ans;
        unordered_set<string>st(wordList.begin(),wordList.end());//st will be used to check if current word exist in 
        //wordlist
        queue<vector<string>>q; //instead of  storing the words we are storing th path of words
       unordered_set<string> visited;
        q.push({beginWord});
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto curr_path = q.front();
                q.pop();
                string curr  = curr_path.back();
                // we are changing the each word of beginWord with 26 char and checking if the given 
                //changed word exits in the wordlist if it exists we will  create a vector of string
                //i.e. new_path and store all the word in  that path and insert it into the queue
                //if the if find the changed word is endWord it means a path is completed till last word 
                //and we will update it into ans
                for( int i=0 ;i<curr.size() ;++i){
                     string temp = curr;
                    for(char ch = 'a'; ch<='z' ;++ch){
                         temp[i] = ch;
                        if(st.find(temp)!= st.end()){
                            vector<string> new_path = curr_path;
                            new_path.push_back(temp);
                            visited.insert(temp);//marking it visited so it doesnt get traversed twice
                            if(temp==endWord){
                                ans.push_back(new_path);
                            }
                            else{
                                q.push(new_path);
                            }
                            
                        }
                    }
                }
            }
            //once we mark a word visited we will erase it from the wordlist so it doesnt get traversed twice
                st.erase(s);
            }
        }
        return ans;
    }
};
//Time: O(N * 26 * W^2 + A), where N <= 1000 is number of words in wordList, W <= 5 is length of each words, A is total number of sequences.
//BFS costs O(E + V), where E is number of edges, V is number of vertices.
//Because words need to be existed in the wordList, so there is total N words, it's also the number of vertices.
//To find neighbors for a word, it costs O(26 * W * W), in the worst case, we have to find the neighbors of N words, so there is total O(N * 26 * W^2) edges.
//Space: O(N*W + A)