class Solution {
public:

bool isSame(unordered_map<char, int>& freq1, unordered_map<char, int>& freq2)
{
    // Iterate through the target frequencies (freq2)
    for(auto const& [key, val] : freq2) // Using structured binding for C++17, equivalent to auto x : freq2
    {
        // If character from freq2 is not in freq1, or its count in freq1 is less than in freq2
        if(freq1.find(key) == freq1.end() || freq1[key] < val)
        {
            return false; // Not a valid window
        }
    }
    return true; // All characters in freq2 are present in freq1 with sufficient counts
}



string minWindow(string s, string t) {

        int n1 = s.length();
        int n2 = t.length();

        // Handle edge cases: if t is empty, return an empty string.
        // If s is empty or shorter than t, no valid window exists.
        if (n2 == 0) return "";
        if (n1 == 0 || n1 < n2) return "";

        unordered_map<char, int> freq1; // Frequencies of characters in the current window (s)
        unordered_map<char, int> freq2; // Frequencies of characters in the target string (t)

        // Populate freq2 with target frequencies from string t
        for(int i = 0; i < n2; i++)
        {
            freq2[t[i]]++;
        }

        int left = 0;
        int minLen = INT_MAX; // Initialize minLen to a very large value
        int minWindowStart = 0; // Stores the starting index of the minimum window found

        for(int right = 0; right < n1; right++)
        {
            // Add the current character s[right] to the window's frequency map
            // Only add if it's a character we care about (present in freq2)
            if(freq2.count(s[right])) // Using .count() is safer than .find() != .end() for presence check
            {
                freq1[s[right]]++;
            }
            
            // If the current window (from 'left' to 'right') is valid
            while(isSame(freq1, freq2))
            {
                // Calculate the length of the current valid window
                int currentWindowLen = right - left + 1;

                // If this window is shorter than the minimum found so far
                if(currentWindowLen < minLen)
                {
                    minLen = currentWindowLen;
                    minWindowStart = left; // Store the starting index of this shorter window
                }

                // Attempt to shrink the window from the left
                // Only decrement if the character at s[left] is one we care about (in freq2)
                if(freq2.count(s[left])) {
                    freq1[s[left]]--;
                }
                left++; // Move left pointer
            }
        }

        if (minLen == INT_MAX) {
            return ""; // No valid window found
        }
        else {
            // Return the minimum window substring using the stored start index and length
            return s.substr(minWindowStart, minLen);
        }
    }
};