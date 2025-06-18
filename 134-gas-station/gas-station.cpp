class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //mỗi bài chỉ có một lời giải duy nhất
        int n = gas.size();
        vector <int> pre(n);
        for (int i =0; i<n;i++) pre[i] = gas[i] - cost[i];
        int s = accumulate(pre.begin(), pre.end(), 0);
        if (s<0) return -1;
        int idx = 0, cur = 0;
        for (int i = 0; i<n-1;i++) {
            cur += pre[i];
            if (cur<0) {
                cur = 0;
                idx = i+1;
            }
        }
    return idx; 
    }
};