class Solution
{
    public:
    //to pair the start timing and end timing  
    struct meeting {
        int start;
        int end ;
    };
    //we are sorting according to end time of meeting. WHY?
    //greedy approach: Sooner a meeting ends ..we can take the next meeting 
    bool static comparator(struct meeting m1 ,struct meeting m2){
        return m1.end < m2.end;
    }
    
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    { 
        struct meeting meet[n];
        for(int i =0 ;i<n ; ++i){
            meet[i].start = start[i];
            meet[i].end = end[i];
        }
       
        sort(meet , meet+n,comparator);
        //first meeting is always selected hence maxMeet =1
        int maxMeet = 1;
        int finish = meet[0].e;
        for(int i =1 ;i<n;++i){
            if(meet[i].start>finish){
                maxMeet++;
                finish = meet[i].end;
            }
            
        }
        return maxMeet;
    }
};
//Time Complexity : O(N*LogN)
// Auxilliary Space : O(N)