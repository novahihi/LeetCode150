class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
    //target luôn là một dãy số tăng dần 
    vector <string> res;
    stack <int> a; int k = 0;
    for (int i = 1; i<=n; i++) {
        res.push_back("Push");
        a.push(i);
        if (a.top()==target[k]) k++;
        else {
            a.pop();
            res.push_back("Pop");
        }
        if (k==target.size()) break;
    }   
    return res;
    }
};