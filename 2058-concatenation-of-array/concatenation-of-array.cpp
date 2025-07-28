class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>ans(n*2);
        

        for(int i = 0; i < nums.size(); i++)
        {
            ans[i] = nums[i];
        }

        int j = nums.size();
        for(int i = 0; i < nums.size(); i++)
        {
            ans[j] = nums[i];
            j++;
        }
        return ans;
    }
};