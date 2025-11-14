class Solution {
public:
    void reverseString(vector<char>& s) {
        int leftPtr = 0; 
        int rightPtr = s.size() - 1; 

        while(leftPtr < rightPtr)
        {
            // cond 
            swap(s[leftPtr], s[rightPtr]); 
            
            // update pointers 
            leftPtr++; 
            rightPtr--;
        }
    }
};