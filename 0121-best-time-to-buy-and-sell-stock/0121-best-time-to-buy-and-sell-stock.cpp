class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // ?: want the biggest difference 
            // buy low, sell high
        
        // tech: 2 pointers 
        
        // time & space comp: 
            // time: o(n)
            // space: o(1) 

        // 1. declare variable to return as our final result 
        int maxProfit = 0; 

        // 2. execute 2 pointers method 
        int leftPtr = 0; // buy 
        int rightPtr = 1; // sell 

        // rightPtr is what will mainly be moving forward 
        while(rightPtr < prices.size())
        {
            // CONDITION - check if a profit can be made 
            if(prices[rightPtr] > prices[leftPtr])
            {
                int diff = prices[rightPtr] - prices[leftPtr]; 

                maxProfit = max(maxProfit, diff); 
            }
            else 
            {
                // otherwise, need to update leftPtr bc found an even smaller val w/ rightPtr 
                leftPtr = rightPtr; 
            }

            // always update rightPtr at the end to prepare for next iteration 
            rightPtr++; 
        }

        return maxProfit; 
    }
};