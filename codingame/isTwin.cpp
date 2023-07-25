// C++ implementation​​​​​​‌​‌​​​‌​​​​‌‌‌​‌‌‌‌​‌​​‌‌ below
#include <cctype>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

/*
A twin of a word is a word written with the same letters (case insensitive) but not necessarily in the same order.

For example Silent is a twin of Listen.

The isTwin(a, b) function should return true if b is the twin of a and false otherwise. a and b are two non-NULL strings.

Write the body of the isTwin(a, b) function.
*/

class Answer
{
public:
    static bool isTwin(string a, string b) {
        std::cerr << "A: " << a << ", B: " << b << std::endl;
        std::transform(a.begin(), a.end(), a.begin(), [](auto c){ return std::tolower(c); });
        std::transform(b.begin(), b.end(), b.begin(), [](auto c){ return std::tolower(c); });
        std::cerr << "A: " << a << ", B: " << b << std::endl;
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        std::cerr << "A: " << a << ", B: " << b << std::endl;
        return a.compare(b) == 0;
    }
};