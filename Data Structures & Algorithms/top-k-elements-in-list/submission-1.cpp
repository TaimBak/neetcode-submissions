class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        // A number can only repeat as many times as the array's size will allow. Therefore, the size of the input array will govern how many the max number of occurances for each value.

        // Create a map that will store the number of times a value has been seen.
        unordered_map<int, int> count;

        // Create an array of values that will store the number of times each value has occured.
        vector<vector<int>> freq(nums.size() + 1);

        // Populates the count map with the number of times each value appears
        for (int value : nums)
            count[value] += 1;

        for (const auto& entry : count)
            freq[entry.second].push_back(entry.first);


        vector<int> result;

        // Loop from back of freq array and insert values into result array until k size is satisfied
        for (int i = freq.size() - 1; i > 0; i--)
        {
            // Accounts for multiple values appearing the same number of times.
            for (auto value : freq[i])
            {
                result.push_back(value);
                if (result.size() >= k)
                    return result;
            }
        }
        

        
    }
};
