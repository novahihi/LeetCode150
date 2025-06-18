class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int n = nums.size();
    vector <pair <int,int>> p (n);
    for (int i = 0; i<n;i++) {
        p[i].first = nums[i];
        p[i].second = i;
    }  
    sort (p.begin(), p.end());
    int i = 1;
    for (int i = 1; i<n; i++) {
        if (p[i].first==p[i-1].first) {
            if (abs(p[i].second - p[i-1].second)<=k) return true;
        }
        else continue;
    }
    return false;
    }
};