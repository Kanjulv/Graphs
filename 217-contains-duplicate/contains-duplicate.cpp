class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        int n = nums.size();

        unordered_map<int, int> freq(0);


        for(int i = 0; i < n; i++)
        {
            if(freq.find(nums[i]) == freq.end())
            {
                freq[nums[i]]++;
            }
            else{
                return true;
            }
        }

        return false;
    }
};