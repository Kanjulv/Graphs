class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int left = 0; 
        int currSum = 0;
        int minLength = INT_MAX;
        
        for(int right = 0; right < nums.size(); right++){

            currSum += nums[right];

            while(currSum >= target)
            {
                minLength = min(minLength, right-left+1);

                currSum -= nums[left++];
            }
        }

        return minLength == INT_MAX ?  0 :  minLength;
    }
};