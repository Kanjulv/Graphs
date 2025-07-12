class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;

        for(auto x : strs)
        {
            string word = x; //make a copy of the current word to perform sort
            sort(word.begin(), word.end());
            mp[word].push_back(x);
        }

        for(auto x : mp)
        {
            ans.push_back(x.second);
        }

        return ans;

    }
};