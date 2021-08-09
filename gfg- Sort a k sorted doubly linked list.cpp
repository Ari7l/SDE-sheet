
struct comparator{
    bool operator()(struct Node* p1 ,struct Node * p2 ){
        return  p1->data>p2->data;
    }
};

struct Node* sortAKSortedDLL(struct Node* head, int k){
        if(!head || !head->next) return head;

        priority_queue< Node* ,vector<Node*>, comparator>pq;
         Node *new_head=NULL ,curr;
         for( int  i=0; head!=NULL && i<=k ;++i){
                pq.push(head);
                head = head->next;   
         }
         while(!pq.empty()){
             if(new_head==NULL){
                 new_head = pq.top();
                 new_head->prev = NULL;
                 curr = new_head;
             }
             else{
                 curr->next = pq.top();
                 pq.top()->prev = curr;
                 curr= pq.top();
             }
             pq.pop();
             if(!head){
                  pq.push(head);
                head = head->next;
             }

         }
         curr->next = NULL;
         return new_head;            


}