class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.empty()) return res;
        sort(intervals.begin(), intervals.end());
        stack<vector<int>> st;
        st.push(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
            vector<int> top = st.top();

            if (intervals[i][0] > top[1]) {
                st.push(intervals[i]);
            } 
            else {
                st.pop();
                top[1] = max(top[1], intervals[i][1]);
                st.push(top);
            }
        }
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
