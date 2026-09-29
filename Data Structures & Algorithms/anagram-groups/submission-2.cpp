#define ABC

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // To aviod the log time complexity of sorting the strings, just create an array that holds the number of times each letter was used. Just a faster way of 'sorting'

        unordered_map<string, vector<string>> groups;

        for (auto& word : strs)
        {
            string key(26, 0);

            for (char c : word)
                key[c - 'a']++;
        
            groups[key].push_back(word);
        }

        vector<vector<string>> result;
        for (auto& entry : groups)
        {
            result.push_back(entry.second);
        }

        return result;
            




        

        
        
    }
};
