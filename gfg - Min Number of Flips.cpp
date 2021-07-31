char flip(char ch){
    return (ch == '0')?'1':'0';
}


int helper(string S , char expected){
    int flipcnt=0;
    for( int i=0 ;i<S.size() ;++i){
        //we are starting with '0' then next must be one if not increment the count
        if(S[i]!=expected){
            flipcnt++;
        }
        //after each operation flip the char
        expected = flip(expected);
    }
    return flipcnt;
}

int minFlips (string S)
{ //we are taking minimum of two scenarios if we start with '0' or '1';
 // then we are checking in which scENARIO  we can take minimum flips
    return min(helper(S,'0') ,helper(S,'1') );
}