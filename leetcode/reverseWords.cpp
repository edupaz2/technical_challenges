class Solution {
public:
    string reverseWords(string s) {
        int idx = s.size()-1;
        string result;
        result.reserve(s.size());
        while (idx >= 0) {
            if(s[idx] == ' ') {
                --idx;
            } else {
                auto endIdx = idx;
                auto startIdx = idx;
                while(idx >= 0 && s[idx] != ' ') {
                    startIdx = idx--;
                }
                if(!result.empty()) {
                    result += ' ';
                }
                result += s.substr(startIdx, endIdx-startIdx+1);
            }
        }
        return result;
    }
};
