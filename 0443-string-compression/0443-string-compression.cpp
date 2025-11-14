class Solution {
public:
    int compress(vector<char>& chars) {
        // tech: 2 pointers! 

        // 1. declare helper variables -- 

        // holds size of array to iterate thr
        int n = chars.size(); 

        // our iterator pointer - iterates thr input 
        int i = 0; 

        // writer pointer - where we write our compressed input
        int k = 0;

        // 2. iterate thr array --
        while(i < n)
        {
            // write the character 
                // use curr val of k first -- 
                    // write char @ i into the array @ pos k
                // then increment k
            chars[k++] = chars[i]; 

            // see how many times this curr char repeats
            int j = i + 1; 
            while(j < n && chars[i] == chars[j])
            {
                // j -- continues moving forward until it hits a diff char
                j++;
            }

            // check if # of repeats > 1 
                // j - i --> is what gets the number of repeats
                // if > 1 --> need to do compression
            if(j - i > 1) 
            {
                string count = to_string(j - i); 
                for(char c : count) 
                {
                    chars[k++] = c; 
                }
            }

            // goes to the next group of new characters
            i = j;
        }
        
        return k;
    }
};