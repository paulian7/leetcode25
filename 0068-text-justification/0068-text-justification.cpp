class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        // 1. declare result to return 
            // where each val in array will be a line
        vector<string> res; 

        // 2. declare var for curr line
        vector<string> line;

        // 3. declare helper variables
            // length -- tracks length of curr line
            // i - pointer 
                // help us iterate thr input
        int length = 0;
        int i = 0;

        // 3. start iterating 
        while(i < words.size())
        {
            // checking if the curr line is complete
                // take length of current line + length of another word + line.size() 
                    // line.size() -- acounts for the spaces, as each word needs a space after it
            if(length + words[i].size() + line.size() <= maxWidth)
            {
                // ====== when the line isn't complete ======
                    // will need to update our curr line
                // add curr word to line 
                line.push_back(words[i]); 
                // update length of line 
                length += words[i].size(); 
                // increment 'i' pointer to move forward to next word in input array
                i++;
            }
            else 
            {
                // ====== when the line IS complete ======
                // calc the number of spaces we need to divide evenly in the line
                    // rmbr - "length" variable does not include the spaces -- which is what makes this computation possible
                int extraSpace = maxWidth - length;

                // calc how we're going to divide the spaces 
                int remainder = extraSpace % max(1, (int)(line.size() - 1));
                int space = extraSpace / max(1, (int)(line.size() - 1));

                // add in the spaces
                    // line.size() - line contains all words in curr line
                        // subtract by 1 bc we don't have a space @ the end of last word 
                        // only adding spaces in btwn words
                for (int j = 0; j < max(1, (int)line.size() - 1); j++) 
                {
                    line[j] += string(space, ' ');
                    if (remainder > 0) 
                    {
                        line[j] += " ";
                        remainder--;
                    }
                }

                string justifiedLine = accumulate(line.begin(), line.end(), string());
                res.push_back(justifiedLine);
                line.clear();
                length = 0;
            }
        }

        // ====== in the case we're HANDLING THE VERY LAST LINE ======
        // take each word and join them together w/ a space in btwn them
        string lastLine = accumulate(line.begin(), line.end(), string(),
                                      [](string a, string b) {
                                            return a.empty() ? b : a + " " + b;
                                        });

        // how to calc the # of spaces left over after joining all the words together w/ a space?
        int trailingSpace = maxWidth - lastLine.size(); 
        // now add trailing space to the end of our "lastLine"
        lastLine += string(trailingSpace, ' ');
        
        // now add lastLine to our result 
        res.push_back(lastLine);

        // ====== RETURN FINAL ANSWER ======
        return res;
    }
};