class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;
        for (auto e: nums) 
        if (e==val) cnt++;
        int k = nums.size() - cnt;
        nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
    return k;
    }
};