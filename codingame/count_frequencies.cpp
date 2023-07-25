#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>

using namespace std;
#include <map>
#include <set>

vector<int> count_frequencies(vector<string> words)
{
    // Write your code here
    // To debug: cerr << "Debug messages..." << endl;

    std::map<string, unsigned int> counter;
    std::set<string> wordsSet;
    for(const auto& w: words) {
        counter[w] = counter[w] + 1;
        wordsSet.insert(w);
    }

    vector<int> result;
    for(auto it = wordsSet.cbegin(); it != wordsSet.cend(); ++it) {
        result.emplace_back(counter[*it]);
    }
    
    return result;
}