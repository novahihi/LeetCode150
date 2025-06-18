class Solution {
public:
    bool wordPattern(string pattern, string s) {
    queue <string> q; string word = "";
    
    for (auto e: s) {
        
        if (e!=' ') {
            word += e;
            continue;
        }
        else {
            q.push(word);
            word = "";
        }
    }    
    if (!word.empty()) q.push(word);
    map <string, char> m1;
    map <char, string> m2;
    int n = pattern.size();
    int m = q.size();
    if (m!=n) return false;
    for (int i = 0; i<n; i++) {
        word = q.front();
        char c = pattern[i];
        if (m1.count(word) && m1[word]!=c) return false;
        if (m2.count(c) && m2[c]!=word) return false;
    m1[word] = c;
    m2[c] = word;
    q.pop();
    }
    
    return true;
    }
};