
class Solution
{
	public:
	    
	    void dfs(string S,int start,int end,vector<string>&ans){
	        if(start==end){
	            ans.push_back(S);
	            return;
	        }
	        else{
	            for(int i=start;i<=end;++i){
	            swap(S[start],S[i]);
	            dfs(S,start+1,end,ans);
	             swap(S[start],S[i]);
	        } 
	        }
	       
	    }
		vector<string>find_permutation(string S)
		{   int n = S.size();
		    vector<string>ans;
		    dfs(S,0,n-1,ans);
		    return ans;
		}
};
//Expected Time Complexity: O(n! * n) here are n! permutations and it requires O(n) time to print single permutation.

//Expected Space Complexity: O(n)

//Approach 2
//if there are duplicate characters and we want only distinct permutations