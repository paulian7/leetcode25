class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        // declare starting variables 
        vector<string> result; 
        vector<string> currLine;
        int currLength = 0; 
        int i = 0; 

        // iterate thr input until we reach the last line
        while(i < words.size())
        {
            if(currLength + words[i].length() + currLine.size() <= maxWidth)
            {
                currLine.push_back(words[i]); 
                currLength += words[i].length(); 
                i++; 
            }
            else 
            {
                // need to add spaces btwn all the words now 

                // deal w/ space calculations
                int extraSpace = maxWidth - currLength;
                int spaces = extraSpace / max(1, (int)(currLine.size() - 1));
                int remainder = extraSpace % max(1, (int)(currLine.size() - 1));

                // actually add spaces after each word now
                for(int j = 0; j < max(1, (int)(currLine.size() - 1)); j++)
                {
                    currLine[j] += string(spaces, ' '); 
                    if(remainder > 0)
                    {
                        currLine[j] += ' ';
                        remainder--;
                    }
                }

                // add to answer 
                string justifiedLine = accumulate(currLine.begin(), currLine.end(), string());
                result.push_back(justifiedLine); 
                currLine.clear(); 
                currLength = 0;
            }
        }

        // dealing w/ last line 
        string lastLine; 
        // want to ensure we have spaces in btwn each word 
        for(int k = 0; k < currLine.size(); k++)
        {
            // if not dealing w/ last element, add a ' ' after the curr word 
            if(k < currLine.size() - 1)
            {
                lastLine += currLine[k] + ' ';
            }
            else 
            {
                lastLine += currLine[k];
            }
        }

        // deal w/ trailing spaces 
        int trailingSpaces = maxWidth - lastLine.length(); 
        // add the trailing spaces to the last line 
        lastLine += string(trailingSpaces, ' '); 
        // add final line to result 
        result.push_back(lastLine); 

        // return final answer
        return result;
    }
};