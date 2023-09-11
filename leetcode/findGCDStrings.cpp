class Solution {
public:
    bool checkSubstr(const string& str, const string& substr) {
        // precond: str.size % substr.size == 0
        auto idx = 0;
        while(idx != str.size()) {
            if(str.substr(idx, substr.size()) != substr) {
                return false;
            }
            idx += substr.size();
        }
        return true;
    }

    string gcdOfStrings(string str1, string str2) {
        if(str1.size() < str2.size()) {
            for(int i = str1.size(); i >= 1; --i) {
                if(str1.size() % i == 0 && str2.size() % i == 0) {
                    auto substr = str1.substr(0, i);
                    if(checkSubstr(str1, substr) && checkSubstr(str2, substr)) {
                        return substr;
                    }
                }
            }
        } else if(str1.size() > str2.size()) {
            for(int i = str2.size(); i >= 1; --i) {
                if(str1.size() % i == 0 && str2.size() % i == 0) {
                    auto substr = str2.substr(0, i);
                    if(checkSubstr(str1, substr) && checkSubstr(str2, substr)) {
                        return substr;
                    }
                }
            }
        } else {
            return (str1 == str2) ? str1 : "";
        }
        return "";
    }
};
