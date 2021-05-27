class Solution {
public:
    //to find minimum number of positive deci-binary numbers needed so that they sum up to n. 
    //we just need to find the highest digit in the string n. WHy?
    // for any postion x or digit in n , we need x number of 1's to add to that 
    //e.gEg. 
//1. Consider n="9"
 //We need to add 1 for 9 times to get n
   //  2. n = "4201"
// We can add      1101
//               + 1100
//               + 1000 
//               + 1000 
//               -------
//			       4201
//or any other combination which doesnt matter for this quesiton to get n
    int minPartitions(string n) {
        char best = '0';
        for(auto &ch : n){
            if(ch>best) best = ch;
        }
        return best - '0';
    }
};