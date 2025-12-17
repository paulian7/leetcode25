class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // time & space comp: 
            // time: o(n)
            // space: o(1) 
                // unless you count output list --> then o(n)
                
        // 1. start off w/ helper variables && declaring a result to return @ the end
        int numIntervals = intervals.size(); 
        int i = 0; // our iterator

        vector<vector<int>> fixedIntervals; // result

        // 2. iterate thr the intervals -- go thr case by case 

        // CASE 1 == push all the intervals that come BEFORE the new interval first
            // these intervals are the one's that end BEFORE the new interval
            // does not overlap w/ the newInterval @ all
            // ends when we find we reach end of list OR find a val that might overlap w/ newInterval
        while(i < numIntervals && intervals[i][1] < newInterval[0])
        {
            fixedIntervals.push_back(intervals[i]);
            i++;
        }

        // CASE 2 == deal w/ overlapping interval(s)
            // as end of new interval is NOT before the start of the currInterval
            // ... which means there's some overlap occurin somehow
        while(i < numIntervals && newInterval[1] >= intervals[i][0])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);

            i++;
        }
        fixedIntervals.push_back(newInterval);

        // CASE 3 == add any leftover interval(s)
        while(i < numIntervals)
        {
            fixedIntervals.push_back(intervals[i]);
            i++;
        }

        return fixedIntervals;
    }
};