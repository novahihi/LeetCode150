class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map <char, int> freq;
        for (auto e: ransomNote) 
        freq[e]++;
        for (auto e: magazine) {
            auto it = freq.find(e);
            if (it==freq.end()) continue;
            else {
                if ((*it).second > 0) (*it).second--;
                else continue;
            }
        }
        for (auto [k, v]: freq) {
            if (v==0) continue;
            else return false;
        }
        return true;
    }
};