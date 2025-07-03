class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // buy low, sell high 
        // iterate thr our integer array once 
            // trying to find the largest difference 

        // time comp: o(n) 
        // space comp: o(1) 
        
        // 2 pointers 
        int leftPtr = 0; // buy
        int rightPtr = 1; // sell!~ 

        // variable to return at the very end 
        int maxProfit = 0; 

        // want to iterate to the end
        while(rightPtr < prices.size())
        {
            // check if we can have any profit? 
            if(prices[rightPtr] > prices[leftPtr])
            {
                int diff = prices[rightPtr] - prices[leftPtr]; 

                // update final ans of course to return
                maxProfit = max(maxProfit, diff); 
            }
            else 
            {
                // rightPtr is smaller :(
                leftPtr = rightPtr;
            }

            // always ensure we're updating the rightPtr 
                // as that's what's processing each element individually as we go 
            rightPtr++; 
        }

        return maxProfit; 
    }
};