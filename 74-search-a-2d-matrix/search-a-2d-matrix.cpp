class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                ans.push_back(matrix[i][j]);
            }
        }

        int start = 0; 
        int end = ans.size() - 1;

        while(start <= end)
        {
            int middle = (start + end) / 2;

            if(ans[middle] == target)
            {
                return true;
            }

            else if(ans[middle] > target)
            {
                end = middle - 1;
            }

            else {
                start = middle + 1;
            }
        }

        return false;
    }
};