#include <type_traits>
#include <vector>

using namespace std;

// do not modify this​​​​​​‌​‌​​​‌​​​​‌‌‌​‌‌​​‌​​​‌‌ structure
typedef struct {
    double x;
    double y;
} Point;

class Pi {
public:
    // approximate pi using the given points
    static double approx(vector<Point> &pts) {
        vector<Point>::size_type counter{0};
        for(const auto& p : pts) {
            if(p.x * p.x + p.y * p.y <= 1) {
                counter++;
            }
        }
        return 4.0 * counter / pts.size();
	}
};