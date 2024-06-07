
// This is a demo task.

// Write a function:

// int solution(vector<int> &A);

// that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

// For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

// Given A = [1, 2, 3], the function should return 4.

// Given A = [−1, −3], the function should return 1.

// Write an efficient algorithm for the following assumptions:

// N is an integer within the range [1..100,000];
// each element of array A is an integer within the range [−1,000,000..1,000,000].
// Copyright 2009–2024 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <map>
int solution(vector<int> &A) {
    // Implement your solution here
    if(A.size() == 0) return 1;

    std::map<int, bool> existMap;

    for(const auto& elem : A) {
        existMap[elem] = true;
    }
    int i=1;
    for(std::vector<int>::size_type j=0; j<A.size(); ++j) {
        if(existMap.contains(i)) {
            ++i;
            continue;
        }
        return i;
    }
    return A.size()+1;
}
