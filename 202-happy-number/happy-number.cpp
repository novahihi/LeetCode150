class Solution {
public:
    bool isHappy(int n) {
    set<int>s;
    while (true) {
        if (n==1) return true;
        if (s.find(n) != s.end()) break;
        else s.insert(n);
        string s = to_string(n);
        int sum = 0;
        for (char c: s) {
            int digit = c - '0';
            sum += pow(digit,2);
        }
        n = sum;
    }    
    return false;
    }
};