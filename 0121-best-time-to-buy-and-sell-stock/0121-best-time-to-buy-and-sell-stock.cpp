class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // tech: 
            // want to find largest difference... but in one-pass! 
            // 2 pointers 
        
        // time & space comp: 
            // time: o(n)
            // space: o(1)

        // 1. declare variable to return as result 
        int maxProfit = 0; 

        // 2. declare 2 pointers 
        int leftPtr = 0; // buy 
        int rightPtr = 1; // sell 

        // 3. iterate thr array of prices now 
        while(rightPtr < prices.size())
        {
            // check if any profit?? 
            if(prices[rightPtr] > prices[leftPtr])
            {
                int currDiff = prices[rightPtr] - prices[leftPtr]; 
                maxProfit = max(currDiff, maxProfit); 
            }
            else 
            {
                leftPtr = rightPtr; 
            }

            // always update rightPtr for the next iteration 
            rightPtr++;
        }

        return maxProfit;
    }
};