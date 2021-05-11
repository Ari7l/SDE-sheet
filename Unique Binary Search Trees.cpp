Leetcode-Unique Binary Search Trees
// Dp problem
// concept used CATALAN'S NUMBER
//BST right node > root and left node < root 
class Solution {
public:
    int numTrees(int n) {
        int dp[n+1] ; // dp stores the unique BST that can be created with n nodes
        memset(dp ,0, sizeof(dp));
            dp[0] = 1 ; // if no.of nodes is 0 or 1 there is only one BST we can create
            dp[1] =1 ;
    for(int i=2 ;i<=n;++i){ // then we are placing each number i from 1 to n as root and determining the unique BST that can 
                                // be formed by that particular number as root node
        for(int j=0 ;j<i;++j){
            dp[i] += ((dp[j])*(dp[i-j-1])); // the combination can be determined by taking product of no. of nodes in left subtree and right subtree
                                              // e.g 1 2 3 4 5 
                                              //if 3 is root then total unique BST = (1,2) * (4,5) = 4;
                                             // dp[5] = dp[0]*dp[4] + dp[1]*dp[3] + dp[2]*dp[2] + dp[3]*dp[1] + dp[4]*dp[0] 
        }
    }
    return dp[n];
    }
};
// TIME : O(n*n)
// SPACE : O(N)
