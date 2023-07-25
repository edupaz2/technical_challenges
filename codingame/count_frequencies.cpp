#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>

using namespace std;
/*
Objective
In text processing tasks, one of the first things to do is figure out how often each word appears in a given document. In this task, you will be completing a function that returns the unique word frequencies of a tokenized word document.

 
Implementation
Implement the function count_frequencies(words) which takes as input a vector of strings (words), representing a tokenized word document. For example:

['the', 'dog', 'got', 'the', 'bone']
 
Your count_frequencies function should return a vector of integers containing the number of occurrences of each word sorted alphabetically.
 
For the above example, the correct output would be:
[1, 1, 1, 2]  # bone = 1, dog = 1, got = 1, the = 2
*/
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