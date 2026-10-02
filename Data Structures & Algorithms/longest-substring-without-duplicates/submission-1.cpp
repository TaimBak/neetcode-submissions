class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int longest = 0, left = 0;
        unordered_set<char> substr;

        for (int right = 0; right < s.size(); right++)
        {
            while (substr.contains(s[right]))
            {
                substr.erase(s[left]);
                left++;
            }

            substr.insert(s[right]);
            longest = max(longest, right - left + 1);
        }
        
        return longest;
    }
};
