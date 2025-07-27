class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_map<int, int> mp(0);

        for(int i = 0 ; i < nums.size(); i++)
        {
            if(mp[nums[i]] >= 1)
            {
                return true;
            }

            mp[nums[i]]++;
        }

        return false;
    }
};