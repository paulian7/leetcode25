class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        // time & space comp: o(n * m) 
            // n - num of words 
            // m - avg length of the words
        
        // 1. ====== declare starting variables ======
        vector<string> result; // final answer, each element is a "line" 
        vector<string> currLine; // holds all words in the current line 
        int currLength = 0; // holds length of all the words in the currLine 
        int i = 0; // our iterator, iterates word-by-word thr input array

        // 2. ====== iterate thr input loop, justifying ======
            // loop will break once we get to the last word... 
            // ... in which we need to deal w/ trailing spaces
        while(i < words.size())
        {
            // == case 1 - when the line isn't complete yet == 
            if(currLength + words[i].size() + currLine.size() <= maxWidth)
            {
                // can still add another word into curr line... 
                currLine.push_back(words[i]); 
                currLength += words[i].length(); 
                i++; // update iterator to go to next word 
            }
            else 
            {
                // == case 2 - when the line IS complete == 
                    // will need to evenly distribute spaces -> then add to final result

                // ----- deal w/ all the "space calculations" now -----
                int extraSpace = maxWidth - currLength; // all the space we still need to fill 

                // calc num of spaces to put in btwn words specifically 
                    // how much spaces go in btwn a pair of words
                int space = extraSpace / max(1, (int)(currLine.size() - 1));
                
                // calc any spaces left over that we still need to add 
                int remainderSpaces = extraSpace % max(1, (int)(currLine.size() - 1));

                // ----- add all the spaces btwn the words in the line now -----
                for (int j = 0; j < max(1, (int)(currLine.size() - 1)); j++)
                {
                    // add num of spaces needed after curr word
                    currLine[j] += string(space, ' ');
                    // any remainder spaces? 
                        // always 1 remainder added @ each iteration
                    if(remainderSpaces > 0)
                    {
                        currLine[j] += ' ';
                        remainderSpaces--;
                    }
                }

                // ----- finally add currLine to final result -----
                // mush everything together into a string
                string justifiedLine = accumulate(currLine.begin(), currLine.end(), string());
                // add to final result 
                result.push_back(justifiedLine); 
                // reset variables for next line 
                currLine.clear(); 
                currLength = 0;
            }
        }

        // 3. ====== deal w/ the last line that needs to be left-justified ======
        // add 1 space in btwn each word 
        string lastLine;
        for(int k = 0; k < currLine.size(); k++)
        {
            if(k < currLine.size() - 1)
            {
                lastLine += currLine[k] + ' '; // want space to separate itself w/ the next word coming
            }
            else 
            {
                lastLine += currLine[k]; // last word, no want space 
            }
        }

        // add in any trailing spaces
        int trailingSpaces = maxWidth - lastLine.length(); 
        lastLine += string(trailingSpaces, ' ');

        // finally add lastLine to result
        result.push_back(lastLine);

        // 4. ====== return final result ======
        return result;
    }
};