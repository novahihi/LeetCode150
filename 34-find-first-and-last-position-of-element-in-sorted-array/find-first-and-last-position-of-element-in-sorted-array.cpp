class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector <int> res; bool flag = false;
        int i = 0;
        while (i<n) {
            if (nums[i] == target && flag == false) {
                res.push_back(i);
                flag = true;
                continue;
            }
            if ((flag==true) && nums[i]>target) {
                res.push_back(i-1);
                return res;
            }
            i++;
        }
        if (flag) {
            res.push_back(n - 1);
        } else {
            res.push_back(-1);
            res.push_back(-1);
        }
        return res;
    }
};