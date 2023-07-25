#include <iostream>
#include <string>
#include <stack>

using namespace std;
/*
You are given a sequence of characters consisting of parentheses () and brackets []. A string of this type is said to be correct:
if it is an empty string
if the string A is correct, (A) and [A] are correct
if the string A and B are correct, the concatenation AB is also correct
Input: The string contains at most 10 000 characters.

Examples: [()] is correct, (()[]) is correct, ([)] is not correct, (( is not correct.

Implement the method check(string sequence) to check the correctness of a string of this type. check returns true if the string is correct, false otherwise.
*/
class Answer
{
public:
    //! checks that the given sequence is​​​​​​‌​‌​​​‌​​​​‌‌‌‌​‌‌‌‌​‌‌​​ correct
    static bool check(string sequence)
    {
        if(sequence.empty()) return true;
        std::stack<bool> helper; // false for (, true for [
        for(auto it = sequence.cbegin();
            it != sequence.cend();
            ++it) {
            if(*it == '(') {
                helper.push(false);
            } else if(*it == '[') {
                helper.push(true);
            } else if(*it == ')') {
                if(helper.size() && helper.top() == false) {
                    helper.pop();
                } else {
                    return false;
                }
            } else if(*it == ']') {
                if(helper.size() && helper.top() == true) {
                    helper.pop();
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
        return helper.size() == 0;
    }
};