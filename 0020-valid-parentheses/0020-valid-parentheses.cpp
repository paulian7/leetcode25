class Solution {
public:
    bool isValid(string s) {
        // 1. declare our stck 
        stack<char> cStack; 

        // 2. declare hash table
        unordered_map<char, char> closeToOpen = {
            {')', '('}, 
            {'}', '{'},
            {']', '['}
        };

        // 3. start iterating thr string now! 
        for(char c : s)
        {
            // check are we dealing w/ the closing part of the pair?
            if(closeToOpen.count(c))
            {
                // start seeing if we've correctly closed the pair
                if(!cStack.empty() && cStack.top() == closeToOpen[c])
                {
                    cStack.pop(); // pop its matching pair off
                }
                else 
                {
                    return false; // incorrect closing 
                }
            }
            else 
            {
                // dealing w/ open part of the pair
                cStack.push(c);
            }
        }

        return cStack.empty();
    }
};