class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.size();

        int startIdx = 0;
        int maxLen = 1;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j <= 1; ++j) {
                int low = i;
                int high = i+j;
                while(low >= 0 && high < n && s[low] == s[high]) {
                    if((high-low+1) > maxLen) {
                        maxLen = high-low+1;
                        startIdx = low;
                    }
                    --low;
                    ++high;
                }
            }
        }

        return s.substr(startIdx, maxLen);
    }
};
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// Reference: https://leetcode.com/problems/longest-palindromic-substring/solution
// Reference: https://www.geeksforgeeks.org/dsa/longest-palindromic-substring