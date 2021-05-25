
//["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
// ((10 * (6 / ((9 + 3) * -11))) + 17) + 5

class Solution {
public:
    
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto &t:tokens){
            //using double inverted bcoz its a string of one char
            //Reverse Polish Notation was designed specifically to make computing easier with the more                   efficient use of a stack.So we can use a stack here to store numbers until they're used, and                 then each operand will use the top two values of the stack.
            if(t=="+"||t=="-"||t=="*"|| t=="/"){
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                int res=0;
               // Since the order of the numbers is still important for subtraction and division, we'll have                  to make sure that the two numbers are processed in their original order, which is the                           opposite order of the stack.op1 comes after op2
                if(t=="+") res = op2 + op1;
                if(t=="-") res = op2 - op1;
                if(t=="*") res = op2 * op1;
                if(t=="/") res = op2 / op1;
                 st.push(res);
            }
            else{
                
                st.push(stoi(t));
            }
        
    }
        return st.top();
    }
};
//Time Complexity: O(N) where N is the length of tokens
//Space Complexity: O(N) for the length of the stack, up to N / 2 + 1 values