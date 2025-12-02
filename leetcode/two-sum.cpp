class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> store;
        const auto size = nums.size();
        for(int i=0; i<size; ++i) {
            int complement = target - nums[i];
            if(store.contains(complement)) {
                return {i, store[complement]};
            }
            store[nums[i]] = i;
        }
        return {};
    }
};