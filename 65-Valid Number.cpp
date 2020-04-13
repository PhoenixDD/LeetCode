static regex e("^\\s*[-+]?((\\d+)|(\\d+\\.\\d+)|(\\d+\\.)|(\\.\\d+))(e[+-]?\\d+)?\\s*$");
class Solution {
public:
    bool isNumber(string s) 
    {
        return regex_match(s,e);
    }
};