class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = accumulate(cardPoints.begin(),cardPoints.begin()+k,0);//basically taking all the k ele from left side of array
        int ans =sum;
        for(int l = k-1,r=cardPoints.size()-1;l>=0;l--,r--){
        	// we are removing element from the left window of size k and adding element from right and taking maximum sum possible
        	// basically trying all the possible combination
             ans = max(ans,sum+=(cardPoints[r]-cardPoints[l]));
        }
        return ans;
    }
};