//order in vector
class Solution {
    #define MAX 10000 // estimation of digits in factorials
public: 
    //1*2*3*4*5*6*7*8*9*10 = 3628800
    int multiply(int size ,vector<int>&res,int n){
        int carry = 0 ;//initially carry is zero
        //basically we are doing the simple multiplication of 1..N numbers and storing 
        // the right most digits from each multiplication in reverse order in res
        for(int i=0 ;i<size ;++i){
            int product = res[i]*n + carry;
            res[i] = product%10;
            carry = product/10;
        }
        while(carry){
            res[size]=carry%10;
            carry=carry/10;
            size++;
        }
        return size;
    }

    vector<int> factorial(int N){
       vector<int>res(MAX);
        int size = 1;
        res[0]=1;
        // This function multiplies i with the number
        //represented by res[].
        // size is size of res[] or number of digits in the
        // number represented by res[] 
        for(int i=2 ;i<=N;++i){
            size = multiply(size,res,i);
        }
        res.resize(size);
        std::reverse(res.begin(),res.end());
        return res;
    }
};
//ITME:O(N)
