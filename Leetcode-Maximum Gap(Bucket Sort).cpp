public:
    //[[3,6,9,1]
    int maximumGap(vector<int>& nums) {
        
        if (nums.size() < 2) return 0;
        int hi = 0, lo = INT_MAX, ans = 0;
        // finding the max and min number in the vector
        for (auto& n : nums)
            hi = max(hi, n), lo = min(lo, n);
        //determine the average gap/smallest maximum gap possible
        int bsize = max(int((hi - lo + nums.size() -2) / (nums.size() - 1)), 1) ;//ceil value
        //e.g (9-1)/3 = 2.33 but we want 3 
        
        vector<vector<int>> buckets(nums.size(), vector<int>()); //defining buckets 
        //(n-lo)/bsize puts the ele in their sorted bucket
        //four elements 3 buckets 
        //e.g -1-----3- -6----- -9-----
        //(3-1)/3 = 0 hence 3 is going to be in the first/0th bucket
        for (auto& n : nums)
            buckets[(n - lo) / bsize].push_back(n);
        
        //once all the elements are in the their respective buckets
        //we need to find the max and min elements in the each bucket (currlo and currhi)
        //if their is only one elem then currlo==currhi
        //the maximum gap is given by finding the differe between the previous bucket highest ele
        //i.e prevhi and current buckte minimun ele i.e. currlo
        int currhi = 0;
        for (auto& b : buckets) {
            if (b.empty()) continue;
            //prevhi will be the last bucket's highest ele

            int prevhi = currhi ? currhi : b[0], currlo = b[0];
            for (auto& n : b)
                currhi = max(currhi, n), currlo = min(currlo, n);
            ans = max(ans, currlo - prevhi);
        }
        return ans;
    }
};