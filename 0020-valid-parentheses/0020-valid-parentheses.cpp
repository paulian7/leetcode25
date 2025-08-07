class Solution {
public:
    bool isValid(string s) {
        // tech: 
            // hash table - will cross check to see if open closed correctly 
            // stacks! 
        
        // time & space comp: 
            // time: 
            // space: 
        
        // 1. declare stack
        stack<char> cStack;

        // 2. declare hash table to work w/ 
        unordered_map<char, char> closeToOpen = {
            {')', '('}, 
            {'}', '{'},
            {']', '['}
        };

        // 3. iterate thr string 
        for(int i = 0; i < s.length(); i++)
        {
            // check if dealing w/ closing paren 
            if(closeToOpen.count(s[i]))
            {
                // dealing w/ closing! 
                if(!cStack.empty() && cStack.top() == closeToOpen[s[i]])
                {
                    cStack.pop(); // pop off open paren, has been prop closed!
                }
                else 
                {
                    return false; // no proper closure
                }
            }
            else 
            {
                cStack.push(s[i]);
            }
        }



        // 4. returns true if stack empty 
            // empty means all open paren has closed!
        return cStack.empty(); 
    }
};