class Solution {
public:
    int search(vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size()-1;
    
    //Finding mid element
    int midElement = (start + end)/2;

    while(start <= end){

    if(target == nums[midElement]) 
    {
        return midElement;
    }
    
    if (target > nums[midElement])
    {
        start = midElement + 1;
    }

    else if (target < nums[midElement])
    {
        end = midElement - 1;
    }

    midElement = (start + end)/2;
    }

    return -1;
}
};
