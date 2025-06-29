class Solution {
public:
    string intToRoman(int num) {
    string res;
    const vector <pair <int, string>> valroman {
       {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
            {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
            {5, "V"},    {4, "IV"},   {1, "I"} 
    };
    
    for (const auto [val, rom] : valroman) {
        if (num == 0) break;
        while (num>=val) {
            res+=rom;
            num-=val;
        }
    }
    return res;
    }
};