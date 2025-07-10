class Solution {
public:
    int singleNumber(vector<int>& nums) {
    unordered_map <int,int> freq;
    for (int i = 0; i<nums.size(); i++) freq[nums[i]]++;
    for (auto [k,v]:freq) {
        if (v==1) return k;
    }
    return 0;
    }
};