class Solution {
public:
    int jump(vector<int>& nums) {
    int n = nums.size(); int cnt = 0;
    if (n==1) return 0; int max = 0;
    int j; int i = 0; int flag;
        while (i<n) {
        j = i + nums[i];
        cnt++;
        if (j>=n-1) return cnt;
        while (j>i) {
            int t = j + nums[j];
            if (t>max) {
                flag = j;
                max = t;
            }
            j--;
        }
        i = flag;
        }
    cnt = cnt+1;
    return cnt;
    }
    
};