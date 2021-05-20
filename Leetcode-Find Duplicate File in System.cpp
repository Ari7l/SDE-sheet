class Solution {
public:
    // to return the file path which have same content we are using a map(key, value)
    //but in this case the content of the file is key and the file path will be stored as 
    // value hence we will check if any content has >1 value 
    vector<vector<string>> findDuplicate(vector<string>& paths) {
       unordered_map<string ,vector<string>>cont; //abcd --> "root/a/2.txt"
                                                  //     --> "root/c/d/4.txt"
        
        //Choose auto x when you want to work with copies.
        //Choose auto &x when you want to work with original items and may modify them.
        //Choose auto const &x when you want to work with original items and will not modify them.
       for(auto &pstr : paths){
           int i=0;
       //"root/a 1.txt(abcd) in the input once the path and name of the file have a space in between 
           //hence we itreate till we hit space and then store the path string
           while(pstr[i]!=' ') ++i;
           string path = pstr.substr(0,i);
           //now we will itrate the rest of the string to extract content 
           //j will store the starting index of the name of content
           for(int j=i+1 ,k=0 ;i<pstr.size();++i){
               if(pstr[i]=='('){
                   k = i+1;
               }
               else if(pstr[i]==')'){
                   //pathfile must be in this format "directory_path/file_name.txt"
                   string pathfile = path +'/' + pstr.substr(j,k-j-1);
                    string content = pstr.substr(k,i-k);
                   if(cont.find(content)==cont.end()){
                       // if this the new content then we will crete new vector to store all the
                       //pathfile corresponding to content
                       cont[content] = vector<string>();
                   }
                   cont[content].push_back(pathfile);//if content is already there just push the pathfile
                    j = i + 2;//becoz there is space between two strings
               }
           }
           
       }
        vector<vector<string>>res;
           for(auto &kv:cont){
               if(kv.second.size()>1){
                   // if the size of any vector is greater than 1 it means it contains
                   //duplicate path
                   res.push_back(kv.second);
               }
           }
           return res;
        
    }
};
