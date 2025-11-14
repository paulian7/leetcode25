class Solution {
public:
    void reverseString(vector<char>& s) {
        int leftPtr = 0; 
        int rightPtr = s.size() - 1; 

        while(leftPtr < rightPtr)
        {
            // temp var 
            char tempC = s[rightPtr];

            // swap 
            s[rightPtr] = s[leftPtr]; 
            s[leftPtr] = tempC;

            // update pointers
            leftPtr++;
            rightPtr--;
        }
    }
};