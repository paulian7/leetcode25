class Solution {
public:
    void reverseString(vector<char>& s) {
        // tech: 2 pointers 

        // 1. declare pointers 
        int leftPtr = 0; 
        int rightPtr = s.size() - 1; 

        while(leftPtr < rightPtr)
        {
            swap(s[leftPtr], s[rightPtr]);

            leftPtr++; 
            rightPtr--;
        }
    }
};