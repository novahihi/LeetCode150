class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
    vector <int> res (2);
    sort(nums.begin(), nums.end());
    if (nums[0]!=1) res[1] = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i-1]==nums[i]) 
        {res[0] = nums[i];
        if (res[1]==0) res[1] = nums[i] + 1;
        }
        if (nums[i]-2==nums[i-1]) res[1] = nums[i-1] + 1;
    }
    if (nums[nums.size()-1]!=nums.size()) res [1] = nums.size();
    return res;
    }
};