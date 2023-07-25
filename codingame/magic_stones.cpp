// C++ implementation​​​​​​‌​‌​​​‌​​​​‌‌‌‌‌​​​​​‌‌​‌ below
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Answer
{
    public:
        static int magic(vector<int> stones) {
            cerr << "Stones: ";
            std::map<int, int> counter;
            int max_level = 0;
            for(auto it = stones.cbegin(); it != stones.cend(); ++it) {
                cerr << *it << ", ";
                counter[*it] = counter[*it] + 1;
                if (*it > max_level)
                    max_level = *it;
            }
            cerr << endl;

            unsigned int level = 1;
            int total_stones = 0;
            do {
                int count = counter[level];
                if(count > 1) {
                    counter[level+1] = counter[level+1] + counter[level] / 2;
                    if (level+1 > max_level) max_level = level+1;
                    total_stones += counter[level] % 2;
                } else if(count == 1){
                    total_stones++;
                }
                cerr << "Level " << level << ", count: " << count << ", total: " << total_stones << endl; 
                level++;
            } while (level <= max_level);
            return total_stones;
        }
};