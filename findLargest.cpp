#include <iostream>
#include <limits>

using namespace std;

class Algorithm
{
public:
    /** @return the largest number in the given array​​​​​​‌​‌​​​‌​​​​‌‌‌​‌‌​​‌‌​​‌​ */
    static int findLargest(int numbers[], int length)
    {
        int largest{std::numeric_limits<int>::min()};
		for(int i = 0; i < length; ++i) {
            if(numbers[i] > largest) {
                largest = numbers[i];
            }
        }
        return largest;
	}
};