class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if(s.empty())
        {
            return 0;
        }

        int left = 0;
        unordered_map <char, int> count(0);
        int maxLength = 0;

        for(int right = 0; right < s.length(); right++)
        {
            while(count[s[right]] > 0)
            {
                count[s[left]]--;
                left++;
            }

            count[s[right]]++;
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;

    }
};