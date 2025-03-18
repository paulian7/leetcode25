class Solution {
public:
    bool isValid(string s) {
        // tech: stacks and hash table as help --> time comp: o(n) 
            // rmbr - stacks are LIFO (last in first out rule) 

        // 1. declare stack
        stack<char> cStack; 

        // 2. declare hash table to help track closed & opened parenthes: 
        unordered_map<char, char> closeToOpen = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        // 3. FINALLY iterate through string 
        for(char c : s)
        {
            // check if we're dealing with a closing parenthesis 
                // count(c) --> checks if the key "c" exists in the hash table 
            if(closeToOpen.count(c))
            {
                // checks that stack is NOT empty and if we have matching open parenthesis
                if(!cStack.empty() && cStack.top() == closeToOpen[c])
                {
                    cStack.pop(); // pops element from top of stack
                }
                else 
                {
                    return false; // as we don't have matching pair
                }
            }
            else 
            {
                // dealing with an OPEN parenthesis as we couldn't find it as a key 
                    // keys are the closing parenthesis 
                cStack.push(c);
            }
        }

        // if stack's empty --> succesfully closed everything! 
        return cStack.empty();
    }
};