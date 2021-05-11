class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            vector<int>res;
            unordered_map<int,int>mp1;
            unordered_map<int,int>mp2;
           for(int i=0;i<n1 ;i++){
               if(mp1[A[i]]) continue;
               mp1[A[i]]++;
           }
           for(int i=0;i<n2 ;i++){
               if(mp2[B[i]]) continue;
               mp2[B[i]]++;
           }
           int ele=0;
           for(int i=0 ;i<n3 ;++i){
               if(mp1[C[i]] && mp2[C[i]]){ //If the element exists in both A and B 
                  if(ele != C[i]){ // Duplicate element must inserted only once
                       res.push_back(C[i]);
                       ele = C[i];
                  }
                       
               }
           }
           return res;
            //code here.
        }

};
TIME:O(n1+n2+n3) = O(N)
SPACE : O(n1+n2+n3)
