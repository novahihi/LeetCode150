class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
    vector <string> res;
    if (nums.empty()) return res;
    string word;
    int n = nums.size();
    int start = 0;
    int i = 1; 
    while (i<n) {
        if (nums[i]!=(nums[i-1]+1)) {
            if (start==(i-1)) word = to_string(nums[start]);
            else word = to_string(nums[start]) + "->" + to_string(nums[i-1]);
            res.push_back(word);
            start = i;
        }
        i++;
    }
    if (start == (n-1)) word = to_string(nums[start]);
    else word = to_string(nums[start]) + "->" + to_string(nums[n-1]);    
    res.push_back(word);  
    return res;
    }
};