class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int t = 1;  
        for (int i = 1; i < nums.size(); i++) {
            
            if (nums[i] != nums[i - 1]) {
                nums[t] = nums[i];
                t++;
            }
        }
        return t;
    }
};