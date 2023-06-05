// C++ implementation​​​​​​‌​‌​​​‌​​​​‌‌‌​‌‌‌‌​‌​​‌‌ below
#include <cctype>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

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