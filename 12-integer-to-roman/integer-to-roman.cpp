class Solution {
public:
    string intToRoman(int num) {
        vector<int> vals = {
        1000, 900, 500, 400,
         100,  90,  50,  40,
          10,   9,   5,   4,
           1
    };
    vector<string> syms = {
        "M", "CM", "D", "CD",
        "C", "XC", "L", "XL",
        "X", "IX", "V", "IV",
        "I"
    };

    string res;
    for (size_t i = 0; i < vals.size() && num > 0; ++i) {
        while (num >= vals[i]) {
            num -= vals[i];
            res += syms[i];
        }
    }
    return res;
        
    }
};