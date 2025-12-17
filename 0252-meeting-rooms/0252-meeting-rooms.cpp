class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        // time & space comp: 
            // time: o(n logn) 
                // nlogn - sort() 
                // n - iteratin thr -> but overall simplifies down to just nlogn
            // space: o(1) - sort happens in-place
        
        // 0. cover edge case 
        if(intervals.empty())
        {
            return true;
        }

        // 1. sort intervals by startPt
        sort(intervals.begin(), intervals.end());

        // 2. iterate thr sorted intervals
            // start at i = 1 bc we want to check...
            // ... 2nd interval's startPt against 1st interval's endPt
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] < intervals[i - 1][1])
            {
                return false;
            }
        }

        return true;
    }
};