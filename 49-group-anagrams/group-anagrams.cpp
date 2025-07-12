class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    int n = strs.size(); string word;
    multimap <string , string> m;
    for (int i = 0; i<n; i++) {
        word = strs[i];
        sort(strs[i].begin(), strs[i].end());
        m.insert({strs[i], word});
    }
    
    vector<vector<string>> res;
    res.push_back({});
    int cnt = 0;
    auto it = m.begin();
    res[cnt].push_back(it->second);
    word = it->first;
    m.erase(m.begin());
    for(auto[k,v]: m) {
        if (k!=word) {
            cnt++;
            res.push_back({});
            res[cnt].push_back(v);
            word = k;
        }
        else res[cnt].push_back(v);
    }
    return res;
    }
};