class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Can be solved using hashmaps but will need 0(n) space for that.
        //Can be solved using sorting but will need 0(nlogn) time

        //Therefore solved using Boyer-Moore's voting algorithm

        int candidate = 0;
        int majority = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(majority == 0) candidate = nums[i];

            if(nums[i] == candidate) majority += 1;
            else majority -= 1;
        }

        return candidate;
    }
};