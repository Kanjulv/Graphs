class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n, 1);

        int i = 0;
        int curr = 1;

        while(i < n)
        {
            ans[i] *= curr;
            curr *= nums[i];
            i++;
        }

        i = n - 1;
        curr = 1;

        while(i >= 0)
        {
            ans[i] *= curr;
            curr *= nums[i];
            i--;
        }

        return ans;
    }
};

