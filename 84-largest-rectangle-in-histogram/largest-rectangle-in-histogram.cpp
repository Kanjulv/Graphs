class Solution {
public:
vector <int> nextSmallestElement(vector <int> arr, int n)
{
    stack <int> stack;
    stack.push(-1);
    vector <int> ans(n); //Answer array

    for(int i = n-1 ; i >= 0; i--)
    {
        while(stack.top() != -1 && arr[i] <= arr[stack.top()])
        {
        stack.pop();
        }
        ans[i] = stack.top();
        stack.push(i);
    }
    return ans;
}

vector <int> prevSmallestElement(vector <int> arr, int n)
{
    stack <int> stack;
    stack.push(-1);
    vector <int> ans(n); //Answer array

    for(int i = 0 ; i < n; i++)
    {
        while(stack.top() != -1 && arr[i] <= arr[stack.top()])
        {
        stack.pop();
        }
        ans[i] = stack.top();
        stack.push(i);
    }
    return ans;
}

    int largestRectangleArea(vector<int>& heights) {
        int area = INT_MIN;
        int n = heights.size();
        vector <int> next = nextSmallestElement(heights, n);
        vector <int> prev = prevSmallestElement(heights, n);

        for(int i = 0; i < n; i++)
    {
        int length = heights[i];
        if(next[i] == -1)
        {
            next[i] = n;
        }
        int breadth = next[i]-prev[i]-1;
        int areaSeperate = length*breadth;
        area = max(area, areaSeperate);
    }
    return area;
    }
};