// you can use includes, for example:
#include <algorithm>
#include <unordered_map>

// NOTE: the use of map is O(N**2) but unordered_map is O(N) or O(N*logN)

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // Implement your solution here
    if(A.size() == 0 || A.size() % 2 == 0) {
        return -1;
    }

    std::unordered_map<int, bool> B;
    for(vector<int>::size_type i = 0; i < A.size(); ++i) {
        if(B.find(A[i]) != B.end()) 
        {
            B.erase(A[i]);
        } else {
            B[A[i]] = true;
        }
    }
    auto is_true = [](auto it) { return it.second; };
    auto it = std::find_if(B.begin(), B.end(), is_true);
    if(it != B.end()) {
        return it->first;
    } else {
        return -1;
    }
}
