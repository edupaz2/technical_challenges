#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>

using namespace std;

string performSwap(vector<int>& source, char sourceID, vector<int>& destination, char destinationID)
{
    string command;
    command.push_back(sourceID);
    command.push_back(' ');
    command.push_back(destinationID);
    destination.push_back(source.back());
    source.pop_back();
    return command;
}

vector<string> solve(vector<int> boxesA, vector<int> boxesB, vector<int> boxesC)
{
    // Write your code here
    // To debug: cerr << "Debug messages..." << endl;
    vector<string> result;
    // Get the boxes out of A
    while(boxesA.size()) {
        result.push_back(performSwap(boxesA, 'A', boxesB, 'B'));
    }
    // Move the boxes from B and C to A
    while(boxesB.size() || boxesC.size()) {
        cerr << "A: " << boxesA.back() << "(" << boxesA.size() << "), ";
        cerr << "B: " << boxesB.back() << "(" << boxesB.size() << "), ";
        cerr << "C: " << boxesC.back() << "(" << boxesC.size() << ")" << endl;
        if(boxesC.size() == 0 || boxesB.back() >= boxesC.back()) {
            cerr << "Choosing B" << endl;
            // Find the right place for the new box in A.
            while(boxesA.size() && boxesB.back() > boxesA.back()) {
                result.push_back(performSwap(boxesA, 'A', boxesC, 'C'));
            }
            result.push_back(performSwap(boxesB, 'B', boxesA, 'A'));
        } else {
            // Find the right place for the new box in A.
            cerr << "Choosing C" << endl;
            while(boxesA.size() && boxesC.back() > boxesA.back()) {
                result.push_back(performSwap(boxesA, 'A', boxesB, 'B'));
            }
            result.push_back(performSwap(boxesC, 'C', boxesA, 'A'));
        }
    }
    cerr << "Result: ";
    for(auto r: result) {
        cerr << r << ", ";
    }
    cerr << endl;
    
    return result;
}

/* Ignore and do not change the code below */
int main()
{
    int boxes_count_a;
    cin >> boxes_count_a; cin.ignore();
    vector<int> boxes_a;
    for (int i = 0; i < boxes_count_a; i++) {
        int boxes_a_tmp;
        cin >> boxes_a_tmp;
        boxes_a.push_back(boxes_a_tmp);
    }
    int boxes_count_b;
    cin >> boxes_count_b; cin.ignore();
    vector<int> boxes_b;
    for (int i = 0; i < boxes_count_b; i++) {
        int boxes_b_tmp;
        cin >> boxes_b_tmp;
        boxes_b.push_back(boxes_b_tmp);
    }
    int boxes_count_c;
    cin >> boxes_count_c; cin.ignore();
    vector<int> boxes_c;
    for (int i = 0; i < boxes_count_c; i++) {
        int boxes_c_tmp;
        cin >> boxes_c_tmp;
        boxes_c.push_back(boxes_c_tmp);
    }
    int std_out_fd = dup(1);
    dup2(2, 1);
    vector<string> actions = solve(boxes_a, boxes_b, boxes_c);
    dup2(std_out_fd, 1);
    for (int i = 0; i < actions.size(); i++) {
        cout << actions[i] << endl;
    }
}
/* Ignore and do not change the code above */