#define ABC 26

class Solution {
public:
    bool isAnagram(string s, string t) {

        //Create a map for each string and increment for values found in s and decrement for values found in t: O(n+m)

        if (s.length() != t.length())
            return false;

        unordered_map<char, int> compare;
        
        for (int i = 0; i < ABC; i++)
            compare[i + 'a'] = 0;

        for (int i = 0; i < s.length(); i++)
        {
            compare[s[i]]++;
            compare[t[i]]--;
        }
        for (const auto& pair : compare)
            if (pair.second)
                return false;

        return true;
    }
};
