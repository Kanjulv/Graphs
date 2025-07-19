class Solution {
public:

vector<int> prevSmallest(vector<int>& heights)
{
    int n = heights.size();
    vector<int> ans(n);
    stack<int> st;

    st.push(-1);

    for(int i = 0; i < n; i++)
    {
        while(st.top() != -1 && heights[i] <= heights[st.top()])
        {
            st.pop();
        }

        ans[i] = st.top();
        st.push(i);
    }

    return ans;

}

vector<int> nextSmallest(vector<int>& heights)
{
    int n = heights.size();
    vector<int> ans(n);
    stack<int> st;

    st.push(-1);

    for(int i = n-1; i >= 0; i--)
    {
        while(st.top() != -1 && heights[i] <= heights[st.top()])
        {
            st.pop();
        }

        ans[i] = st.top();
        st.push(i);
    }

    return ans;

}
    int largestRectangleArea(vector<int>& heights) {

        vector<int> nextSmallestArr = nextSmallest(heights);
        vector<int> prevSmallestArr = prevSmallest(heights);

        int finalArea = INT_MIN;

        for(int i = 0 ; i < heights.size(); i++)
        {
            if(nextSmallestArr[i] == -1)
            {
                nextSmallestArr[i] = heights.size(); 
            }
            int height = heights[i];
            int width = nextSmallestArr[i] - prevSmallestArr[i] - 1;

            int currArea = width * height;

            finalArea = max(currArea, finalArea);
        }

        return finalArea;
    }
};