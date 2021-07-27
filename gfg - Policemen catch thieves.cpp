#include <iostream>
using namespace std;
//Greedy approach
// C++ program to find maximum number of thieves
// caught
#include <iostream>
#include <vector>
#include <cmath>

int maxThievies(char arr[] ,int n,int k){
    std::vector<int>pol;
    vector<int>thi;
    int res = 0;
    int p = 0 ,t=0;
    for(int i=0 ;i<n;++i){
        if(arr[i]=='P'){
            pol.push_back(i);
        }
        else{
            thi.push_back(i);
        }
    }
    while(p<pol.size() && t<thi.size()){
        if(abs(p-t)<=k){
            res++;
            p++;
            t++;
        }
        else if(thi[t]<pol[p]){
            t++;
        }
        else{
            p++;
        }
    }
    return res;
    
}
int main() {
    char arr1[] = { 'P', 'T', 'T', 'P', 'T' };
    int k = 2;
    int n = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Maximum thieves caught: "
         << maxThievies(arr1, n, k) << endl;
	return 0;
}