#include <iostream>
using namespace std;
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(*a))

//Greedy approach
// C++ program to find maximum number of thieves
// caught
#include <iostream>
#include <vector>
#include <cmath>

int dfs(string needle ,int i ,int j ,string str[],int n ,int m ,int len){
    int found = 0;
    if(i>=0 && j>=0 && i<=n && j<=m && needle[len]== str[i][j]){
        char match = needle[len];
        len+=1 ; //first charcter is already matched so try next char
        str[i][j]=0;//traversed already hence marking zero 
        if(len==needle.size()){
            found =1;
        }//if all charcters found return 1;
        else{
            //traversing in all directions
             found += dfs(needle,i+1,j,str,m,n,len);
            found += dfs(needle,i,j+1,str,m,n,len);
            found += dfs(needle,i-1,j,str,m,n,len);
            found += dfs(needle,i,j-1,str,m,n,len);
            
        }
        str[i][j] = match; //bactracing and putting charcters back into their positions
       
    }
    return found;
    
}
//traversing character by char assuming char in 2D array as first char 
//of string to be matched and counting the occurances
int searchString(string needle , int r ,int c, string str[] ,int row ,int col){
    int found =0;
    for(int i=0;i<row;++i){
        for(int j =0; j<col ;++j){
            found += dfs(needle ,i,j,str,row-1,col-1,0) ;
        }
    }
    return found;
}
int main()
{
    string needle = "MAGIC";
    string input[] = { "BBABBM",
                       "CBMBBA",
                       "IBABBG",
                       "GOZBBI",
                       "ABBBBC",
                       "MCIGAM" };
    string str[ARRAY_SIZE(input)];
    int i;
    for (i = 0; i < ARRAY_SIZE(input); ++i)
    {
        str[i] = input[i];
    }
 
    cout << "count: " << searchString(needle, 0, 0, str,
                                      ARRAY_SIZE(str),
                                      str[0].size()) << endl;
    return 0;
}