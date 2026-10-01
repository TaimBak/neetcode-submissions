class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Make an array that will store all of the products except the one one at the index.
        vector<int> prods(nums.size());

        prods[0] = 1;

        for (int i = 1; i < prods.size(); i++)
            prods[i] = nums[i - 1] * prods[i - 1];
        
        int right_prod = 1;
        for (int i = prods.size() - 1; i >= 0; i--)
        {
            prods[i] *= right_prod;
            right_prod *= nums[i];
        }

        return prods;
        
    }
};
