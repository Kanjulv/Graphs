class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int left = 0;
        int n = s.length();
        unordered_map<char, int> count(0);

        int maxLen = 0;
        
        for(int right = 0; right < n ; right++)
        {
            while(count[s[right]] > 0)
            {
                count[s[left]]--;
                left++;
            }

            count[s[right]]++;
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};