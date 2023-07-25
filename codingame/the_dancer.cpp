using namespace std;

#include <array>

class Algorithm
{
public:
    /** @return the position of the dancer at stage n​​​​​​‌​‌​​​‌​​​​‌‌‌‌​‌‌‌‌‌‌‌​‌ */
    static int getPositionAt(int n)
    {
        std::array<int, 6> moves{0, 1, -1, -4, -5, -3};
        return moves[n % 6];
    }
};
