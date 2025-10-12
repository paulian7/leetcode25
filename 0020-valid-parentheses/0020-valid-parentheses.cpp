class Solution {
public:
    bool isValid(string s) {
        // tech: dealing w/ pairs 
            // want the pairs in some corr order 
        
        // time & space comp: 
            // time: o(n)
            // space: o(n)
        
        // 1. declare stack
        stack<char> cStack;

        // 2. declare hash table to cross reference 
        unordered_map<char, char> closeToOpen = {
            {')', '('}, 
            {'}', '{'}, 
            {']', '['}
        };

        // 3. iterate thr string 
        for(char c : s)
        {
            // check dealing w/ close or open paren
            if(closeToOpen.count(c))
            {
                // dealing w/ closed -- 
                // check if have match or not
                if(!cStack.empty() && cStack.top() == closeToOpen[c])
                {
                    // got a match! pop the open paren now 
                    cStack.pop(); 
                }
                else 
                {
                    // no match :( --> return false immediately 
                    return false; 
                }
            }
            else 
            {
                // dealing w/ open 
                cStack.push(c);
            }
        }

        // 4. if stack empty --> valid :) 
        return cStack.empty();
    }
};