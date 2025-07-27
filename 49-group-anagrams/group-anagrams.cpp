class Solution {
public:

bool isAnagram(string s, string t)
{
    unordered_map<char, int> freq1;
    unordered_map<char, int> freq2;

    for(int i = 0; i < s.length(); i++)
    {
        freq1[s[i]]++;
    }

    for(int i = 0; i < t.length(); i++)
    {
        freq2[t[i]]++;
    }

    return freq1 == freq2;
}
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;

        for(int i = 0; i < strs.size(); i++)
        {
            string word = strs[i];
            sort(word.begin(), word.end());

            if(isAnagram(word, strs[i]))
            {
                mp[word].push_back(strs[i]);
            }
        }

        for(auto x: mp)
        {
            ans.push_back(x.second);
        }

        return ans;
    }
};