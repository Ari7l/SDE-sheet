// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends

int countRev(string s)
{
    int cntL= 0; //counts the left brackets
    int cntR = 0;//counts the right brackets
    int n = s.size();
    if(n%2!=0) return -1;
    int res =0;
    for(int i=0 ;i<n ;++i){
        //if we find the left bracket increment cntL
        if(s[i]=='{') cntL++;
        //if the no. of left brack is zero , either is means we balanced 
        //the left brackets with the right brackets or we have encountered 
        // unbalanced right brackets e.g }{{ here cntL=0 initially
        //hence we increment the right count
        else{
            if(cntL==0){
                cntR++;
            }
            else{
                //cancelling out the unbalanced right brackets
                cntL--;
            }
        } 
    }
    //following code returns the res =  ceil(cntL / 2) + ceil(cntR / 2);
    if(cntL&1)cntL = cntL/2 +1;
    else cntL = cntL/2;
    if(cntR&1)cntR = cntR/2 +1;
    else cntR = cntR/2;
    return cntL+cntR;
}
//Expected Time Complexity: O(|S|).
//Expected Auxiliary Space: O(1)