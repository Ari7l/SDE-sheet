//Brute Force approch
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>>ans;
        vector<string>temp;
        sort(products.begin(),products.end());// sort the strings in lexicographical order
        string curr = "";
        for(auto &ch:searchWord){
            curr+=ch;//current substring to be searched
            temp.clear();
            for(auto &prod:products){
                //if the typed search word matches the string put it in temp
                if(prod.substr(0,curr.length())==curr){
                    temp.push_back(prod);
                }
                // we only want three strings 
                if(temp.size()==3) break;
            }
            ans.push_back(temp);
        }
        return ans;
        
    }
};
//TIME:O(N*N) works for small input 
//SPACE : O(N*N)

//2nd Approch Binary Search
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
       vector<vector<string>>ans;
        vector<string>temp;
        sort(products.begin(),products.end());// sort the strings in lexicographical order
        string curr = "";
        auto it = products.begin();
        for(auto &ch:searchWord){
            curr+=ch;//current substring to be searched
            temp.clear();
            //std::lower_bound does not check if an element is part of a sorted range.      Instead it finds the leftmost place where an element could be inserted without breaking the ordering.
            it = lower_bound(it,products.end(),curr);
            for(int i=0 ;i<3;++i){
                //if no match found
                if(it+i==products.end()) break;
                string &str = *(it+i);
                //all the string to the right of iterator may have the curr string
                //hence we have to confirm it and if it doesnt match the other to the right
                //also wont satisfy the condition so break the loop
                if(str.substr(0,curr.length())!=curr) break;
                temp.push_back(str);
            }
            ans.push_back(temp);
        }
        return ans; 
    }
};
//TIME : O(NMlog(N*M)) where N=size of the list and M=average length of the string due to sorting.