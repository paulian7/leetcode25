class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // time: o(nlogn) 
            // iterating thr - o(n)
            // sort - o(nlogn) 
        // space: 

        // 0. declare final result to return @ end 
        int result = 0;

        // 1. sort the list of intervals 
        sort(intervals.begin(), intervals.end());

        // 2. initially keep track of first endVal -> continuously update as we go thr
        int prevEndPt = intervals[0][1];

        // 3. iterate thr the remaining list of intervals
        for(int i = 1; i < intervals.size(); i++)
        {
            // check if NOT OVERLAPPING first
                // if startPt >= prevEndPt -> no overlap
                // as the currInterval comes after the previous interval
                // the = in >= -> helps us with the edge case as [1, 2], [2, 3] are ok
            if(intervals[i][0] >= prevEndPt)
            {
                // so, update our prevEndPt to currInterval's endVal 
                    // as that WILL be bigger
                prevEndPt = intervals[i][1];
            }
            else 
            {
                // we're dealing w/ an overlap -> want to remove an intervals
                result++;

                // want to keep the interval that ends first -> as this leaves room for future intervals
                    // ... which in turn minimizes the total num of intervals we'll need to remove later
                // logically removing the interval w/ the later end-time here
                prevEndPt = min(prevEndPt, intervals[i][1]);
            }
        }

        // 4. return final answer
        return result;
    }
};