class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // If I iterate through the array, I will need to compare each value to each other
        // This can be done by brute force via 2 nested arrays, checking each pair.
        // An unordered map can see if the difference between a target and current value
        // has been seen before, returns the pair which contains the value and the index.

        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); i++)
        {
            // Create an iterator that returns the index of the diff if found
            int diff = target - nums[i];
            auto it = seen.find(diff);
            if (it != seen.end())
                return {it->second, i};
            else
                seen.insert({nums[i], i});
        }

        return {0, 0};
    }
};
