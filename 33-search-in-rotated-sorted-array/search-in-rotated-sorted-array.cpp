class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int start = 0;
        int end = n - 1;

        while(start <= end)
        {
            int mid = start + (end - start) / 2;

            if(target == nums[mid])
            {
                return mid;
            }

            //Check if left part is sorted
            if(nums[mid] >= nums[start])
            {
                //Apply Binary search here
                if(target >= nums[start] && target < nums[mid])
                {
                    end = mid - 1;
                }
                else{
                    start = mid + 1;
                }
            }

            //Else check if right part is sorted
            else
            {
                //Apply Binary search
                if(target <= nums[end] && target > nums[mid])
                {
                    start = mid + 1;
                }

                else{
                    end = mid - 1;
                }
            }

            mid = start + (end - start) / 2;
    }
    return -1;
    }
};