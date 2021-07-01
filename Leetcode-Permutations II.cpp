class Solution {
public:
    
    void permutate(vector<int>&temp,vector<vector<int>>&res, map<int,int>&mp, int start){
        if(start<=0){ //base case when all the elements are used
            res.push_back(temp);
            return ;
        }
        //to avoid duplicate permutations we are using map
        for(auto &p:mp){
            if(p.second<=0) continue;
            p.second--;
            temp.push_back(p.first);
            permutate(temp,res,mp,start-1);
            temp.pop_back();
            p.second++;
            
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       map<int,int>mp;
        vector<int>temp;
        for(int i:nums){
            mp[i]++;
        }
        vector<vector<int>>res;
         if(nums.size()<=1){
             res.push_back(nums);
             return res;
         }
        permutate(temp,res,mp,nums.size());
        return res;
    }
};
//Time : O(n!)