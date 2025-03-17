class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // tech: linear search --> time comp: o(n)

        int numOfIntervals = intervals.size(); 
        int i = 0; 

        // updated vector of arrays to return w/ corrected intervals 
        vector<vector<int>> res; 

        // deal w/ case 1 - when currInterval's endPt is < start of newInterval:
            // aka: normal as usual 
            // add all intervals before the new interval as nothing overlaps YET
        while(i < numOfIntervals && intervals[i][1] < newInterval[0])
        {
            // add currInterval to final result then :) 
            res.push_back(intervals[i]); 

            // incremenet iterator to look at next interval in list
            i++;
        }

        // deal w/ case 2 - DEALING W/ MERGING 
            // merges all the overlapping intervals w/ the newInterval introduced 
            // aka when the start of the currInterval is < endPt of new interval 
        while(i < numOfIntervals && intervals[i][0] <= newInterval[1])
        {
            // grabs new merged start pt 
            newInterval[0] = min(intervals[i][0], newInterval[0]); 
            // grabs new merged end pt
            newInterval[1] = max(intervals[i][1], newInterval[1]); 
            
            // incr iterator to look at next interval in list 
            i++;
        }
        // finally now add in the newInterval after resolving any merges 
        res.push_back(newInterval);

        // deal 2/ case 3 - handles any non-overlapping intervals leftover 
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