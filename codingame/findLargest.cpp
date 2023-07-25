#include <iostream>
#include <limits>

using namespace std;

/*
Algorithm::findLargest(int numbers[], int length) should return the largest number from the array numbers.
length (the size of the array numbers) is always greater than or equal to 1.

Implement Algorithm::findLargest(int numbers[], int length).
*/

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