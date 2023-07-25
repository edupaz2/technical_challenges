#include <type_traits>
#include <vector>

using namespace std;
/*
The technique is as follows: 
Take a random point P at coordinate (x, y) such that 0 ≤ x ≤ 1 and 0 ≤ y ≤ 1. If x² + y² ≤ 1, then the point is inside the quarter disk of radius 1, otherwise the point is outside.
 

Fig 1. An example using 33 random points.
 
We know that the probability that the point is inside the quarter disk is equal to π/4.
 
Write the method double approx(vector<Point> & pts) who will use the points pts to return an approximation of the number π.
 
Input:
Each item in pts is a point.
A point is represented by a structure containing exactly two numbers, respectively, x and y such that 0 ≤ x ≤ 1 and 0 ≤ y ≤ 1.
pts always contains at least one item.
*/

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