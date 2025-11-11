class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // tech: want to find the largest difference in one pass 
            // but numbers are scrambled
        
        // time & space comp: 
            // time: o(n)
            // space: o(1)
        
        // 1. establish pointers 
        int leftPtr = 0; // buy 

        // 2. establish var to return as final result
        int maxProfit = 0; 

        // 3. start iterating thr input array 
        for(int rightPtr = 1; rightPtr < prices.size(); rightPtr++)
        {
            // check for difference 
            if(prices[rightPtr] > prices[leftPtr])
            {
                int currDiff = prices[rightPtr] - prices[leftPtr]; 

                maxProfit = max(maxProfit, currDiff);
            }
            else 
            {
                // we found small val in rightPtr -> want to swap vals
                leftPtr = rightPtr;
            }
        }

        return maxProfit;
    }
};