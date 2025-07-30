class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // tech: 
            // want to find largest difference in one-pass 
            // 2 pointers type method 

        // time & space comp:
            // time: o(n)
                // everything behaving in a linear fashion 
                // no pointers ever go backwards
            // space: o(1) -- just using pointers (isn't much in comparison to a whole array)
        
        // 1. start 2 pointers method -- starting vals for now! 
        int leftPtr = 0; // buy 
        int rightPtr = 1; // when we sell! 

        // 2. start doing our one-pass 
            // rightPtr acts as our type of iterator! 
        int maxProfit = 0; 
        while(rightPtr < prices.size())
        {
            // check if we reached a certain condition 
                // aka if we can find a difference
            if(prices[rightPtr] > prices[leftPtr])
            {
                int diff = prices[rightPtr] - prices[leftPtr]; 

                // update maxProfit 
                maxProfit = max(maxProfit, diff); 
            }
            else 
            {
                // need to update pointers bc we found an even smaller val in rightPtr's 
                leftPtr = rightPtr; 
            }

            // always update rightPtr to move things along 
            rightPtr++; 
        }

        return maxProfit; 
    }
};