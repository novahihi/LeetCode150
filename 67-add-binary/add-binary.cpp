class Solution {
public:
    string addBinary(string a, string b) {
    string res = ""
;    int n;
    if (a.size()>b.size()) {
        n = a.size() - b.size();
        while (n!=0) {
            b = '0' + b;
            n--;
        }
        n = a.size();
    }
    else {
        n = b.size() - a.size();
        while (n!=0) {
            a = '0' + a;
            n--;
        }
        n = b.size();
    }
    int carry = 0;
    for (int i = n-1; i>=0;i--) {
        if (carry==0) {
            if (a[i]== '0' && b[i] == '0') res = '0' + res;
            else if ( (a[i]=='0' && b[i]=='1') || (a[i] == '1' && b[i]== '0') ) res = '1' + res; 
            else {
                res = '0' + res;
                carry = 1;
            }
        }
        else {
            if (a[i]== '0' && b[i] == '0') {
                res = '1' + res;
                carry = 0;
            }
            else if ( (a[i] == '0' && b[i]== '1') || (a[i] == '1' && b[i]=='0') ) res = '0' + res;
            else res = '1' + res;
        }
    }
    if (carry==1) res = '1' + res; 
    return res;
    }
};