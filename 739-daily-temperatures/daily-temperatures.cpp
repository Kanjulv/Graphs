class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        vector<int> res(temperatures.size(), 0);
        stack <int> st;

        for(int i = 0; i < temperatures.size(); i++)
        {
            while(!st.empty() && temperatures[i] > temperatures[st.top()])
            {
                int idx = st.top();
                res[idx] = i - idx;
                st.pop();
            }
            st.push(i);
        }

        return res;
    }
};