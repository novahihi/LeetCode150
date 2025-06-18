class Solution {
public:
    bool isAnagram(string s, string t) {
    if (s.size()!=t.size()) return false;
    multiset <char> ms;
    for (auto e: s) ms.insert(e);
    for (auto e: t)   {
        auto it = ms.find(e);
        if (it != ms.end()) ms.erase(it);
    }
    if (ms.empty()) return true;
    else return false;
    }
};