class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> index;
        vector<int>ans;

        for(int i = 0; i < nums.size(); i++)
        {
            index[nums[i]] = i;
        }


        for(int i = 0; i < nums.size(); i++)
        {
            int currSum = target - nums[i];

            if(index.find(currSum) != index.end() && index[currSum] != i)
            {
                ans.push_back(i);
                ans.push_back(index[currSum]);
                break;
            }
        }

        return ans;
    }
};