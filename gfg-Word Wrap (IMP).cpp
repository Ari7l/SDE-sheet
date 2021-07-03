
class Solution {
public:
    int solveWordWrap(vector<int>nums, int k) 
    {   int res =0;
        int n = nums.size();
        int dp[n];//dp[i] stores the min cost for ith line
        dp[n-1] = 0; //the last line doesnt need the extra space
        int currLen = 0; //stores the space occpied by the words in current line
        //we are going backwards i.e adding new line above last line 
        // i =n-2 because we dont need to calculate for the last line or word
        //we will iterate from the i to the last word to see which arrangement
        //will give the minimum cost
        int cost = 0;
        for(int i=n-2 ; i>=0 ;--i){
            currLen = -1;
            dp[i] = INT_MAX;
            for(int j=i;j<n;++j){
                currLen += nums[j]+1; //adding one for the space between two words
                //e.g. bb cc
                if(currLen>k) break ;//it means current word cannot be added into 
                // the line move to different word
                if(j==n-1){
                    cost = 0;//for last line
                }
                else{
                    //dp[j+1] adds the minimum cost for the line after current 
                    //line 
                    cost = (k-currLen) * (k-currLen) + dp[j+1];
                }
                if (cost < dp[i]) {
                 dp[i] = cost;
                 res = dp[i];
                        }
    
                
            }
            
        }
        return res;
    } 
};
//Expected Time Complexity: O(n2)
//Expected Space Complexity: O(n)