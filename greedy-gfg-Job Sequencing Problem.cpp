/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{   //sorting in desecending order of profit
    bool static cmp(Job max , Job min){
        return max.profit>min.profit;
    }
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,cmp);
        int maxProfit = 0;
        int jobDone = 0;
        int maxDeadline = 0;
        vector<int>res;
        for(int i=0 ;i<n;++i){
            maxDeadline = max(maxDeadline,arr[i].dead);
        }
        //maxDeadline is used to determine the max deadline for any job among all
        //becoz all the jobs can only done till the maximum deadline
        //each job takes 1 unit of time ..bigger deadline means that job can 
        //completed later but within its deadline 
        //e.g. if dead line is 3 then the job can be done witin 0_1_2_3
        // any of the slots i.e 1 to 3 or 0 to 1 etc.
        vector<int>timeslot(maxDeadline+1,false);//creating the time slots and marking 
        // all of them free
        //now iterate through each job
        for(int i = 0 ;i<n;++i){
            for(int t = arr[i].dead ;t>0 ;t--){
                //if we assign the greatest possible time slot since if we assign a time slot even lesser than
                //the available one than there might be some other job(which can maximize profit) which will miss its deadline. 
                //if that timeslot is not free move to next closet possiblw slot
                if(timeslot[t]==false){
                    timeslot[t]=true;
                    maxProfit+=arr[i].profit;
                    jobDone++;
                    break;
                }
            }
        }
        res.push_back(jobDone);
         res.push_back(maxProfit);
        return res;
        // your code here
    } 
};
//Time Complexity: O(N*N)
// Auxilliary Space: O(N)
