class Solution {
public:
    // nested class (public members) to create a job object 
    class job {
        public:
            int start, end, profit;
    };
    
    // sorting jobs : increasing order of end times
    static bool sortFnc(job A, job B) {
        return A.end < B.end;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int size = profit.size();
        
        // creating job vector from given input vectors
        vector<job> jobs(size);
        for(int i = 0; i < size; i++) {
            jobs[i].start = startTime[i];
            jobs[i].end = endTime[i];
            jobs[i].profit = profit[i];
        }
        
        // sorting jobs : increasing order of end times
        sort(jobs.begin(),jobs.end(),sortFnc);
        
        // dp : maximum profit at end of i_th job
        vector<int> maxProfit(size);
        maxProfit[0] = jobs[0].profit; // if only one job exists
        
        for(int idx = 1; idx <= size-1; idx++) {
            
            // looking for previous non overlapping case of max profit which can be combined with current profit
            int prevNonOverlapMaxProfit = 0;
            for(int j = idx-1; j >= 0; j--) {
                if(jobs[j].end <= jobs[idx].start) {
                    prevNonOverlapMaxProfit = maxProfit[j];
                    break;
                }
            }
            
            // max profit at any point : 
            // max(excluding i_th job, including i_th job)
            
            // in order to include i_th job we must look for (previous + non overlapping + maximum profit) case
            // otherwise we won't be able to include i_th job
            maxProfit[idx] = max(maxProfit[idx-1], prevNonOverlapMaxProfit + jobs[idx].profit);
        }
        
        return maxProfit[size-1];
    }
};