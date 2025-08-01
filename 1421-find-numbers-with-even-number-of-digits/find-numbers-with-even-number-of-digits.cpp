class Solution {
public:
    int findNumbers(vector<int>& nums) {
        
        int finalCount = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            int count = 0;
            int quotient = nums[i];
        
        while(quotient > 0)
        {
            int digit = quotient % 10;
            quotient = quotient / 10;

            count++;
        }

        if(count % 2 == 0)
        {
            finalCount++;
        }
    }
    return finalCount;
    }
};