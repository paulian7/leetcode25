class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // tech: linear search --> time comp: o(n) 

        int numOfIntervals = intervals.size(); 
        int i = 0; 

        // updated vector of arrays to return w/ the corrected intervals 
        vector<vector<int>> res; 

        // Deal w/ Case 1 - when currInterval's endPt is < start of newInterval.. so currInterval goes first
            // aka: adds all intervals before the new interval that do not overlap with it
        while(i < numOfIntervals && intervals[i][1] < newInterval[0])
        {
            // add currInterval to final result then :) 
            res.push_back(intervals[i]); 

            // increment iterator to look at next interval in the list 
            i++;
        }

        // Deal w/ Case 2 - DEALING W/ MERGING
            // merges all the overlapping intervals w/ the newInterval introduced :(
            // aka: when start of currInterval is < the endPt of new interval 
        while(i < numOfIntervals && newInterval[1] >= intervals[i][0])
        {
            // grabs new merged start pt
            newInterval[0] = min(newInterval[0], intervals[i][0]); 
            // grabs new merged end pt 
            newInterval[1] = max(newInterval[1], intervals[i][1]);

            // incr iteratior to look at next interval in list 
            i++; 
        }
        res.push_back(newInterval); 

        // Deal w/ Case 3 - handles any non-overlapping intervals leftover
            // adds remaining intervals after the newInterval 
            // bc we already dealt w/ all the overlapping intervals 
        while(i < numOfIntervals)
        {
            res.push_back(intervals[i]); 
            i++;
        }

        return res;
    }
};