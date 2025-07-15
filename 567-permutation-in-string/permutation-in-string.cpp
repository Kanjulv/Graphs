class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.length() > s2.length())
        {
            return false;
        }

        unordered_map<char, int> freq1;
        unordered_map<char, int> freq2;

        //Step 1 - Populate the first map with the first string 
        for(int i = 0; i < s1.length(); i++)
        {
            freq1[s1[i]]++;
            //Step 2- Enter the frequencies of the characters in the first window
            freq2[s2[i]]++;
        }

        //check if the first string is permutation
        if(freq1 == freq2) return true;

        //check for the remaining string using sliding window

        int left = 0;
        for(int right = s1.length(); right < s2.length(); right++)
        {
            freq2[s2[right]]++; //At s1.length(); -> s1.length + 1 -> +2
            freq2[s2[left]]--; //At 0 -> + 1 -> + 2 

            if(freq2[s2[left]] == 0) freq2.erase(s2[left]); //Erase if the element count becomes 0

            left++;

            if(freq1 == freq2) return true;
        }

        return false;

        
    }
};