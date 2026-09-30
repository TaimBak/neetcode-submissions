class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        int largestSeq = 0;

        if (nums.empty())
            return largestSeq;

        if (nums.size() == 1)
            return 1;

        unordered_set<int> hash(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if (!hash.contains(nums[i] - 1))
            {
                int j = 1;
                while (hash.contains(nums[i] + j))
                    j++;
                
                largestSeq = max(largestSeq, j);
            }
        }

        return largestSeq;
    }
};
