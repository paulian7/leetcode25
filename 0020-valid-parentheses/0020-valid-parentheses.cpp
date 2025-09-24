class Solution {
public:
    bool isValid(string s) {
        // tech: stacks & hash table
            // stacks -- to ensure paren. all closed correctly 
            // hash tables -- helps us reference the corr matching pairs w/ one another
        
        // time & space comp: 
            // time:
            // space: 
        
        // 1. declare stack 
        stack<char> parenStack;

        // 2. declare hash table to be used as reference 
        unordered_map<char, char> closeToOpen = {
            {')', '('}, 
            {'}', '{'}, 
            {']', '['}, 
        }; 

        // 3. iterate thr string 
        for(char c : s)
        {
            // check what paren (close or open) we're dealing w/
            if(closeToOpen.count(c)) // check for closing paren 
            {
                if(!parenStack.empty() && parenStack.top() == closeToOpen[c])
                {
                    // pop open paren from top of stack
                    // bc we've found a matching pair!
                    parenStack.pop(); 
                }
                else 
                {
                    return false; // unsuccessful matching :(
                }
            }
            else 
            {
                // dealing w/ open paren --> so add to stack to later be popped
                parenStack.push(c);
            }
        }

        // 4. IF stack is EMPTY --> we've closed everything, so return true! 
        return parenStack.empty();
    }
};