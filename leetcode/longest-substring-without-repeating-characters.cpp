class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int n = s.size();
        if (!n) return 0;
        int longest = 1;
        for(int i=0; i<n-1; ++i) {
            std::unordered_set<char> set{string.at(i)};
            for(int j=i+1; j<n; ++j) {
                if (!set.contains(string.at(j))) {
                    set.emplace(string.at(j));
                    longest = std::max(longest, set.size());
                }
            }
        }
        return longest;
    }
};