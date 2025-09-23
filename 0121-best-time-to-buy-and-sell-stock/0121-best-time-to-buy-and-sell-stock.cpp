class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // tech: want maximum profit
            // want BUY LOW, SELL HIGH --> 2 pointers 

        // time & space comp: 
            // time: o(n)
            // space: o(1) 
                // using a constant number of integer variables -- no big extra data structures
        
        // 1. declare variable to return as final result
        int maxProfit = 0;

        // 2. execute 2 ptrs method
        int leftPtr = 0; // buy 
        int rightPtr = 1; // sell 

        // 3. iterate thr
            // rightPtr is acting as our iterator here 
        while(rightPtr < prices.size())
        {
            // CONDITION -- check. if a profit can be made 
            if(prices[rightPtr] > prices[leftPtr])
            {
                int diff = prices[rightPtr] - prices[leftPtr]; 

                // update maxProfit appropriately 
                maxProfit = max(maxProfit, diff);
            }
            else 
            {
                // need to update leftPtr bc found even smaller val in rightPtr
                leftPtr = rightPtr;
            }

            // always ensure you update rightPtr to prepare for next iteration 
            rightPtr++;
        }

        return maxProfit;
    }
};