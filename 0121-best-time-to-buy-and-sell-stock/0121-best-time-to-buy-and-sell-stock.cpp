class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // tech: want to find largest diff 
            // buy low, sell high --> use 2 pointers!~ 
        
        // time & space comp: 
            // time: o(n)
            // space: o(1)

        // 1. declare var to return as final result 
        int maxProfit = 0; 

        // 2. execute 2 pointers method
        int buyPtr = 0; // when we buy
        int sellPtr = 1; // when se sell 

        // 3. start iterating thr
            // rightPtr acts like our "iterator"
        while(sellPtr < prices.size())
        {
            // CONDITION -- check if a profit can be made 
            if(prices[sellPtr] > prices[buyPtr])
            {
                // check currProfit 
                int diff = prices[sellPtr] - prices[buyPtr]; 

                // update maxProfit accordingly 
                maxProfit = max(diff, maxProfit); 
            }
            else 
            {
                // otherwise, we found an even smaller val in rightPtr
                    // need to swap the 2 vals
                buyPtr = sellPtr;
            }

            // always update rightPtr to prep for next iteration 
            sellPtr++;
        }

        return maxProfit; 
    }
};