#include <string>
#include <unordered_map>
#include <climits> // For INT_MAX

class Solution {
public:
    string minWindow(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();

        if (n2 == 0) { // If t is empty, any window is valid, so s is the min window
            return ""; // Or s, depending on interpretation. Typically, an empty string if t is empty.
        }
        if (n1 == 0 || n1 < n2) {
            return ""; // If s is empty, or s is shorter than t, no valid window
        }

        unordered_map<char, int> targetFreq; // Frequency of characters in t
        for (char c : t) {
            targetFreq[c]++;
        }

        int left = 0;
        int right = 0;
        int matchedCount = 0; // Count of characters in current window that match targetFreq requirements
        int minLen = INT_MAX;
        int minStart = 0;

        unordered_map<char, int> windowFreq; // Frequency of characters in the current window

        while (right < n1) {
            char currentChar = s[right];

            // Expand the window
            if (targetFreq.count(currentChar)) { // If current character is needed
                windowFreq[currentChar]++;
                if (windowFreq[currentChar] <= targetFreq[currentChar]) {
                    // This character contributes to matching the target
                    matchedCount++;
                }
            }

            // Try to shrink the window if we have a valid candidate
            while (matchedCount == n2) { // We have found a window that contains all characters of t
                // Update minimum window found so far
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }

                char charFromLeft = s[left];

                // Shrink the window from the left
                if (targetFreq.count(charFromLeft)) { // If the character being removed was needed
                    if (windowFreq[charFromLeft] <= targetFreq[charFromLeft]) {
                        // This character was contributing to the matchedCount, so decrement it
                        matchedCount--;
                    }
                    windowFreq[charFromLeft]--;
                }
                left++;
            }
            right++;
        }

        if (minLen == INT_MAX) {
            return ""; // No valid window found
        } else {
            return s.substr(minStart, minLen);
        }
    }
};