class Solution {
public:

int helper(string &s , int left , int right, int k)
{
     if(right - left < k)
        {
            return 0;
        }

    unordered_map<char, int> freq;

    for(int i = left; i < right; i++)
    {
        freq[s[i]]++;
    }

    for(int i = left; i < right; i++)
    {
       if(freq[s[i]] < k)
       {
        int next = i + 1;
        while(next < right && freq[s[next]] < k) next++;

        return max(helper(s, left, i, k), helper(s, next, right, k));
       }
    }

    return right - left;
}

    int longestSubstring(string s, int k) {
        int left = 0;
        int right = s.length();

        return helper(s, left, right, k);
    }
};