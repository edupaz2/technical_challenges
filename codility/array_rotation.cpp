// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(vector<int> &A, int K) {
    // Implement your solution here
    if(A.size()) {
        for(int k=0; k<K; ++k) {
            int previous = A[0], current = A[0];
            for(vector<int>::size_type i=1; i < A.size(); ++i) {
                current = A[i];
                A[i] = previous;
                previous = current;
            }
            A[0] = previous;
        }
    }

    return A;
}
