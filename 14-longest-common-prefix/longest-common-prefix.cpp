class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string ans;

        //Sort the string lexicographically
        sort(strs.begin(), strs.end());

        for(int i = 0; i < strs.size(); i++)
        {
            cout << strs[i];
        }

        string s1 = strs[0];
        string s2 = strs[strs.size() - 1];

        for(int i = 0; i < min(s1.length(), s2.length());i++)
        {
            if(s1[i] == s2[i])
            {
                ans.push_back(s1[i]);
            }

            else{
                break;
            }
        }

        return ans;
    }
};