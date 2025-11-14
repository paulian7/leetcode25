class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // ?: koko can atmost eat one entire pile of bananas in a given hr
            // want to find how many bananas koko can eat under h hours (in the smallest num of hrs)
        
        // tech: binary search
        
        // 1. set up 2 pointers for binary search 
        int leftPtr = 1; // holds smallest 
        int rightPtr = *max_element(piles.begin(), piles.end()); // holds largest

        // 2. declare result to return @ end 
        int result = rightPtr; // set it to maxVal for now

        while(leftPtr <= rightPtr)
        {
            // calc midPt 
            int midPt = leftPtr + (rightPtr - leftPtr) / 2;

            // track how long it'll take us @ rate 'k'
                // to eat all bananas
            long long hours = 0;
            // go thr each pile 
            for(int p : piles)
            {
                // ceil() - rounds val UP  
                hours += ceil(static_cast<double>(p) / midPt);
            }

            // check if @ this rate, we can finish under the 'h'
            if(hours <= h)
            {
                // update result 
                result = midPt; 

                // go to smaller vals, to see if we can get a smaller k
                // that can have her eat all banans under h hours
                rightPtr = midPt - 1;
            }
            else 
            {
                // taking too long, need to eat more bananas 
                // go to bigger vals
                leftPtr = midPt + 1;
            }
        }

        return result;
    }
};