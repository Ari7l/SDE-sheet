class Solution {
public:
    //The Idea is similar to Best Time to Buy and Sell Stock I.
    //But here we we can make atmost two transa. and you must sell the stock before you buy again
    //Here, the cost1 keeps track of the lowest price, and profit1 keeps track of the biggest profit we could get similar to Best Time to Buy and Sell Stock I.
//Then the tricky part comes, how to handle the buying the second stock i.e.cost2 to get max profit2 i.e cost2? 
    //Suppose in real life, you have bought and sold a stock and made $100(this the profit 1) dollar profit. 
    //When you want to purchase a stock which costs you $300 dollars, how would you think this? 
    //You must think, um, I have made $100 profit, so I think this $300 dollar stock is worth $200(cost2 - profit1) 
    //FOR ME since I have hold $100 for free.
//There we go, you got the idea how we calculate cost2!! We just minimize the cost again!! 
    //The profit2 is just making as much profit as possible.!
    //in order to get the max profit eventually, profit1 must be as relatively large as possible to produce a small cost2, 
    //and therefore cost2 can be as less as possible to give us the final max profit2.
    // So now we understand why and where we need to take min or max of all cost and profit variables.....
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cost1 = INT_MAX , cost2 = INT_MAX;
        int profit1 =0, profit2 =0;
        for(int i=0 ;i<n ;++i){
            int curr_day_price = prices[i];
            cost1 = min(cost1,curr_day_price);
            profit1 = max(profit1,curr_day_price-cost1);
            cost2 = min(cost2 , curr_day_price - profit1);
            profit2 = max(profit2 ,curr_day_price - cost2);
            
        }
        return profit2;
    }
};
//TIME : O(N) and SPACE:O(1)