class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // time & space comp: 
            // time: 
            // space: 

        // 0. declare result to return @ end
        vector<vector<int>> mergedIntervals;

        // 1. sort intervals to make things easier on us
        sort(intervals.begin(), intervals.end());

        // 2. start off by adding our first interval to our result
        mergedIntervals.push_back(intervals[0]);

        // 3. now, iterate thr all our intervals
        for(auto& interval : intervals)
        {
            // grab currInterval's startPt
            int startPt = interval[0]; 

            // grab currInterval's endPt
            int endPt = interval[1];

            // grab the lastInterval's endPt
            int lastEndPt = mergedIntervals.back()[1];

            // check if we're dealing w/ merge conflicts
            if(startPt <= lastEndPt)
            {
                // oh no, conflict! 
                mergedIntervals.back()[1] = max(endPt, lastEndPt);
            }
            else 
            {
                // add interval as usual, no conflicts / overlap happening
                mergedIntervals.push_back({startPt, endPt});
            }
        }

        // 4. return final result w/ all intervals w/ no merge conflicts
        return mergedIntervals;
    }
};