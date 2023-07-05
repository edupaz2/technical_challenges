// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int fibonacci(int k) {
    if(k == 0) return 0;
    if(k == 1) return 1;
    return fibonacci(k-1) + fibonacci(k-2);
}

int find_longest_jump(int start_idx, int end_idx, const vector<int>& A) {

    int fib = 1;
    int idx = start_idx;
    int found_idx = start_idx;
    while (idx < end_idx) {
        ++fib;
        idx = start_idx + fibonacci(fib);
        std::cerr << "find - S:" << start_idx << ", idx:" << idx << ", F(" << fib << ")=" << fibonacci(fib) << std::endl;
        if(idx == end_idx) {
            std::cout << "Other side" << std::endl;
            found_idx = idx;
        } else if(idx < end_idx) {
            if(A[idx] == 1) {
                std::cerr << "Found jump at " << idx << std::endl;
                found_idx = idx; // found a jump. check higher
            }
        }
    }

    return found_idx;
}

int solution(vector<int> &A) {
    // Implement your solution here
    int number_of_jumps = 0;
    int start_idx = -1;
    int end_idx = A.size();
    
    while(start_idx < end_idx) {
        std::cerr << "Iter S:" << start_idx << ", E:" << end_idx << std::endl;
        int idx = find_longest_jump(start_idx, end_idx, A);
        std::cerr << "idx:" << idx << std::endl;
        if(idx == start_idx) {
            return -1;
        } else {
            std::cerr << "One more jump" << std::endl;
            number_of_jumps++;
            start_idx = idx;
        }
    }

    return number_of_jumps;
}
