class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> finder;
        vector<int> ans;

        for(int i = 0 ; i < nums.size(); i++)
        {
            finder[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if((finder.find(target - nums[i]) != finder.end()) && (finder[target - nums[i]] != i))
            {
                ans.push_back(i);
                ans.push_back(finder[target-nums[i]]);
                break;
            }
        }

        return ans;
    }
};