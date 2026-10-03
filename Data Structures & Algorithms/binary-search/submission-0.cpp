class Solution {
public:

    int recurr(int l, int r, vector<int>& nums, int target)
    {
        if (l > r)
            return -1;

        int m = l + (r - l) / 2; // Avoid overflows

        if (nums[m] == target)
            return m;
        // Continue recurrsion
        return (nums[m] < target ? recurr(m + 1, r, nums, target)
                                 : recurr(l, m - 1, nums, target));

    }

    int search(vector<int>& nums, int target)
    {
        return recurr(0, nums.size() - 1, nums, target);
    }
};
