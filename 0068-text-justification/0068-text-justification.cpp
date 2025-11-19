class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result; 
        vector<string> currLine; 
        int currLength = 0;
        int i = 0; 

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
                int extraSpace = maxWidth - currLength;
                int spaces = extraSpace / max(1, (int)(currLine.size() - 1));
                int remainder = extraSpace % max(1, (int)(currLine.size() - 1));

                for(int j = 0; j < max(1, (int)(currLine.size() - 1)); j++)
                {
                    currLine[j] += string(spaces, ' '); 
                    if(remainder > 0)
                    {
                        currLine[j] += ' '; 
                        remainder--;
                    }
                }

                string justifiedLine = accumulate(currLine.begin(), currLine.end(), string()); 
                result.push_back(justifiedLine);
                currLine.clear(); 
                currLength = 0;
            }
        }

        string lastLine; 
        for(int k = 0; k < currLine.size(); k++)
        {
            if(k < currLine.size() - 1) 
            {
                lastLine += currLine[k] + ' '; 
            }
            else 
            {
                lastLine += currLine[k];
            }
        }

        int trailingSpaces = maxWidth - lastLine.length(); 
        lastLine += string(trailingSpaces, ' ');
        result.push_back(lastLine); 
        return result;
    }
};