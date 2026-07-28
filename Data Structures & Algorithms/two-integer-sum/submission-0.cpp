class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> indexOf;
        indexOf.reserve(nums.size());

        for(int i=0; i< static_cast<int>( nums.size()); i++)
        {
            int need = target - nums[i];
            if(auto it =  indexOf.find(need); it != indexOf.end())
            {
                return {it->second, i};
            }
            indexOf[nums[i]] = i;
        }
    }
};
