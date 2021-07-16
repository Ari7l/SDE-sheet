//The idea is to first sort the array based on start time, so we can examine the meetings as they take place in 
//order (and be greedy). 
//Suppose we have three meetings: [0, 30], [5, 10], and [15, 20] in sorted order. When we see the second meeting,
// we check if its start time is later than the first meeting's end time. It's not, so we need another room. 
// We then compare the third meeting's start time with the minimum of first two meetings' end times. 
// If there is a meeting that ends before the third meeting starts, then we don't need another room.
//So as we iterate through the array, we need to store each meeting's end time and get the minimum quickly. 
//Min heap is a natural choice
/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
     //we are sorting the intervals based on the 
    static bool cmp(Interval s1 ,Interval s2){
        return s1.start<s2.start;
    } 
    
    int minMeetingRooms(vector<Interval> &intervals) {
        int n = intervals.size();
        if(n<=1) return n;
        sort(intervals.begin(), intervals.end() ,cmp);
        priority_queue<int, vector<int>, greater<int>> heap; //min heap created
        int rooms= 0;
        rooms++; //min 1 room is required
        heap.push(intervals[0].end);
        for(int i=1 ;i<n ;++i){
            if(intervals[i].start<heap.top()){
                rooms++;
            }
            else{
                heap.pop();
            }
            heap.push(intervals[i].end);
        }
        return rooms;

    }
};