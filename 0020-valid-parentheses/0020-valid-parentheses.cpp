class Solution {
public:
    bool isValid(string s) {
        // tech: 
            // want to close things && have things in order 
            // dealing w/ pairs 
            // stack && hash table 

        // time & space comp: 
            // time: o(n)
            // space: o(n)
        
        // 1. declare stack 
        stack<char> cStack;

        // 2. declare hash table to use as reference 
        unordered_map<char, char> hashTab = {
            {')', '('}, 
            {'}', '{'}, 
            {']', '['}
        };

        // 3. iterate thr string 
        for(char c : s)
        {
            // check if dealing w/ close or open paren 
            if(hashTab.count(c)) // check if deal w/ closing paren
            {
                if(!cStack.empty() && cStack.top() == hashTab[c])
                {
                    cStack.pop(); 
                }
                else 
                {
                    return false; 
                }
            }
            else 
            {
                // dealing w/ open paren --> just push to stack to later HOPEFULLY be closed 
                cStack.push(c);
            }
        }

        return cStack.empty();
    }
};