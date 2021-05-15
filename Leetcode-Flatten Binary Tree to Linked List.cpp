  //this is a recursive solution which uses reverse post order traversal R-L-N
    //O(N) Ist approch
    TreeNode* prev=NULL;
    void flatten(TreeNode* root) {
        if(root==NULL) return ;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left =NULL;
        prev = root;
    }


   //2nd Approch : Using stack
    //TIME AND SPACE : O(N)
    
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        stack<TreeNode*>st;
        st.push(root);
    while(!st.empty()){
        TreeNode* curr = st.top();
        st.pop();
        if(curr->right!=NULL){
            st.push(curr->right);
        }
        if(curr->left!=NULL){
            st.push(curr->left);
        }
        if(!st.empty()){
            curr->right = st.top();
        }
        curr->left  = NULL;
        
    }
    
    }

     //3rd Approch
    //TIME : O(N) and SPACE : O(1)
    //3rd Approch
    //TIME : O(N) and SPACE : O(1)
    
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        TreeNode* curr = root;
    while(curr!=NULL){
        if(curr->left!=NULL){
            TreeNode* prev = curr->left;
            while(prev->right!=NULL){
                prev = prev->right;
            }
            prev->right=curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr=curr->right;
        
    }
    
    }
