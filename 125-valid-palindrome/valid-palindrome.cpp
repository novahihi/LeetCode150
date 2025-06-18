class Solution {
public:
    bool isPalindrome(string s) {
        string s1 = "";
        for (char e : s) {
            if (isalnum(e)) {
                s1 += tolower(e);
            }
        }

        int n = s1.size();
        for (int i = 0; i < n / 2; i++) {
            if (s1[i] != s1[n - 1 - i]) return false;
        }
        return true;
    }
};