class Solution {
public:
    bool isValid(string s) {
        // tech: stacks & hash table --> time comp: o(n) 
            // RMBR - stacks are LIFO - (last in first out rule) 
        
        // 1. declare stack
        stack<char> cStack; 

        // 2. declare hash table to help track closed & open parentheses 
        unordered_map<char, char> closeToOpen = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        // 3. FINALLY iterate thr our string 
        for(char c : s) 
        {
            // check if we're dealing w/ CLOSING parentheses 
                // count() - method that checks if the specified val exists as a key in the hash table 
            if(closeToOpen.count(c))
            {
                // check if we have recently come across the OPENING parentheses 
                    // AND if stack is NOT empty 
                if(!cStack.empty() && cStack.top() == closeToOpen[c])
                {
                    cStack.pop(); // pop the opening parentheses from top of stack now bc we found match 
                }
                else 
                {
                    return false; // bc no match found for closing parentheses
                }
            }
            else 
            {
                // THEN we're dealing with a OPEN parentheses
                cStack.push(c); 
            }
        }

        // if empty --> succesfully closed everything! 
        return cStack.empty(); 
    }
};