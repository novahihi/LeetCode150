class Solution {
public:
    bool isSubsequence(string s, string t) {
    int i = 0, j = 0;
    int lens = s.size();
    int lent = t.size();
    while (i<lens) {
        if (j==lent) return false;
        if (s[i] == t[j]) {
            i++;
            j++;
        }
        else j++;
    }  
    return true;
    }
};