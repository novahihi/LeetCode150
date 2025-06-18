class Solution {
public:
    int lengthOfLastWord(string s) {
    reverse(s.begin(), s.end());
    int cnt = 0;
    bool flag = false;
    for (auto e: s) {
        if (e != ' ') flag = true;
        if (flag == true) {
            if (e==' ') return cnt;
            else cnt++;
        }
    }
    return cnt;   
    }
};