class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        auto w1It = word1.begin();
        auto w2It = word2.begin();
        string result;
        result.reserve();
        while(w1It != word1.end() && w2It != word2.end()) {
            result.push_back(*w1It);
            result.push_back(*w2It);
            w1It++;w2It++;
        }
        while(w1It != word1.end()) {
            result.push_back(*w1It);
            w1It++;
        }
        while(w2It != word2.end()) {
            result.push_back(*w2It);
            w2It++;
        }
        return result;
    }
};

