class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // hash tables 
            // grab the frequencies of each element 
        unordered_map<int, int> hashTabFreqs;

        // iterate thr array 
        for(int num : nums)
        {
            if(hashTabFreqs.find(num) != hashTabFreqs.end())
            {
                hashTabFreqs[num]++;
            }
            else 
            {
                hashTabFreqs[num] = 1;
            }
        }

        // find greatest freq - n / 2
        for(auto pair : hashTabFreqs)
        {
            if(pair.second > nums.size() / 2)
            {
                return pair.first;
            }
        }

        return 0;
    }
};