class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        vector<int> lproduct(n);
        vector<int> rproduct(n);
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                lproduct[i] = 1;
            } else {
                lproduct[i] = lproduct[i - 1] * nums[i - 1];
            }
        }
        for (int j = nums.size()-1; j >= 0; j--) {
            if (j == nums.size()-1) {
                rproduct[j] = 1;
            } else {
                rproduct[j] = rproduct[j + 1] * nums[j + 1];
            }
        }
        vector<int> res(n);
        for (int i = 0; i < nums.size(); i++) {
            res[i] = lproduct[i] * rproduct[i];
        }
        return res;
    }
};
