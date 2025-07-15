class Solution {
public:
    int characterReplacement(string s, int k) {

        int left = 0;
        int n = s.length();
        int maxFreq = 0;
        int maxLen = 0;

        unordered_map<char, int> count;

        for(int right = 0; right < n ; right++)
        {
            count[s[right]]++;
            
            maxFreq = max(maxFreq, count[s[right]]);

            if((right - left + 1) - maxFreq <= k)
            {
                maxLen = max(maxLen , right - left + 1);
            }
            else{
                count[s[left]]--;
                left++;
            }
        }

        return maxLen;
    }
};