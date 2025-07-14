class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        int left = 0;
        int right = n-1;
        int leftMax = height[left];
        int rightMax = height[right];
        int totalWater = 0;

        while(left < right)
        {
            if(height[left] < height[right])
            {
                left++;
                leftMax = max(leftMax, height[left]);
                totalWater += leftMax - height[left];
            }

            else{
                right--;
                rightMax = max(rightMax, height[right]);
                totalWater += rightMax - height[right];
            }
        }
        return totalWater;
    }
};