class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n ; i++)
        {
            //Skip the duplicates
            if(i > 0 && nums[i] == nums[i-1])
            {
                continue;
            }

            //Two pointer approach 
            int j = i + 1;
            int k = n-1;

            while(j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];

                if(sum == 0)
                {
                    ans.push_back({nums[i], nums[j], nums[k]});

                    //Keep skipping the duplicates
                    while(j < k && nums[j] == nums[j+1]) j++;
                    while(j < k && nums[k] == nums[k-1]) k--;

                    j++;
                    k--;
                }

                else if(sum > 0){
                    k--;
                }

                else{
                    j++;
                }
            }
        }
        return ans;
    }
};