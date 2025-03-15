class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        // tech: sorting the intervals --> time comp: o(nlogn)

        // 1. cover base case 
        if(intervals.empty())
        {
            return true; // as duh you can attend all the meetings if there's none
        }

        // 2, iterate through all the sorted intervals now 
            // sorts by the startPts 
        sort(intervals.begin(), intervals.end());
        for(int i = 1; i < intervals.size(); i++)
        {
            // check whether or not curr startPt is < prev end point
                // if yes, then meetings overlap --> can attend all :(
            if(intervals[i][0] < intervals[i - 1][1])
            {
                return false;
            }
        }

        return true;
    }
};