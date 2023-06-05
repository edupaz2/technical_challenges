#include <iostream>
#include <string>
#include <stack>

using namespace std;

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