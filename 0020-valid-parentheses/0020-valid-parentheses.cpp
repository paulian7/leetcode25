class Solution {
public:
    bool isValid(string s) {
        // tech: stacks & hash table 
            // RMBR - stacks are LIFO (last in, first out) 

        // time & space comp: 
            // time: o(n) 
            // space: o(n) 
        
        // 1. declare stack 
        stack<char> cStack; 

        // 2. declare hash table to help track closed & open parentheses 
        unordered_map<char, char> closeToOpen = {
            {')', '('}, 
            {']', '['}, 
            {'}', '{'}, 
        };

        // 3. FINALLY iterate thr our string 
        for(char c : s) 
        {
            // check if dealing w/ CLOSING parentheses 
                // count() - method that checks for existence of key in hash table 
            if(closeToOpen.count(c))
            {
                // check if we've recently come across the OPENING paren. && is stack is NOT empty 
                if(!cStack.empty() && cStack.top() == closeToOpen[c])
                {
                    cStack.pop(); // pop open paren. from top of stack bc we've found a match
                }
                else 
                {
                    return false; // no match found for closing paren. 
                }
            }
            else 
            {
                // dealing w/ open paren --> so add to stack to later maybe be popped off by closing paren
                cStack.push(c); 
            }
        }

        // 4. if stack is empty --> we've closed everything --> return true :) 
        return cStack.empty(); 
    }
};