class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        //Sort the string lexicographically
        sort(strs.begin(), strs.end());

        //Pinpoiting the first and last string of the array for comparison
        string s1 = strs[0];
        string s2 = strs[strs.size() - 1];
        string ans;

        for(int i = 0; i < min(s1.size(), s2.size()); i++)
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