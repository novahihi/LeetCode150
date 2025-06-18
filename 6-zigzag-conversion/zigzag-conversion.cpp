class Solution {
public:
    string convert(string s, int numRows) {
    int n = s.size();
    if (numRows == 1 || n <= numRows) return s;
    vector <string> rows (numRows);
    string res = "";
    int r = 0; bool up = false;
     for (int i = 0; i < n; ++i) {
            rows[r].push_back(s[i]);
            if (r == 0) up = false;              
            if (r == numRows-1) up = true;         
            if (up) r--;
            else r++;
        }
    for (auto e : rows) res+=e;
    
    return res;
    }
};