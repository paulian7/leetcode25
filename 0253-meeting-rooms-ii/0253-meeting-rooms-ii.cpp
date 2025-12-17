class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // time & space comp: 
            // time: o(n logn) 
            // space: o(n)

        // 0. declare var to return as result
        int numRooms = 0;

        // 1. declare arrays for all startTimes and endTimes 
        vector<int> startTimes;
        vector<int> endTimes;

        // 2. populate the 2 arrays storing startTimes and endTimes resp.
        for(int i = 0; i < intervals.size(); i++)
        {
            startTimes.push_back(intervals[i][0]); // grab just the startVal
            endTimes.push_back(intervals[i][1]); // grab just the endVal
        }

        // 3. sort the 2 arrays
        sort(startTimes.begin(), startTimes.end());
        sort(endTimes.begin(), endTimes.end());

        // 4. start iterating thr the 2-arrays
        // declar helping variables
        int activeMeetings = 0; // tracks num of active meetings
        int sPtr = 0; // ptr iterating thr startTimes array
        int ePtr = 0; // ptr iterating thr endTimes array
        
        while(sPtr < intervals.size())
        {
            // check for minVal btwn the 2-times 
                // if startTime is minVal -> incr. num of active meetings
            if(startTimes[sPtr] < endTimes[ePtr])
            {
                activeMeetings++;
                // want to also update sPtr to go to next startTime
                sPtr++;
            }
            else 
            {
                // meeting has ended... 
                activeMeetings--;
                ePtr++;
            }

            numRooms = max(numRooms, activeMeetings);
        }

        return numRooms;
    }
};