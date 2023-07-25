#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>

using namespace std;

/*
Objective
Stack the boxes on the platform "A", in order of size (the biggest at the bottom).
  Rules
You work in an automated factory that controls a robotic arm to move boxes. The boxes are positioned in 3 stacks: "A", "B" and "C". The arm can move above each stack to pick or release a box. Your goal is to rearrange the boxes to stack all of them onto the platform "A", in order of size.

Your function is given 3 lists. Each list contains the size of every box in the corresponding stack (from bottom to top).

To succeed, your program must output the list of commands for the arm to execute. A command is composed of two letters separated by a space: the source stack from which to pick a box, and the destination stack onto which to drop the box.

It is not necessary to minimize the number of commands but this number should not exceed 200.

  Implementation
Implement the function solve(boxesA, boxesB, boxesC) which takes 3 arrays of integers: boxes_a, boxes_b and boxes_c. The function must return a vector of strings: the name of the source stack and the name of the destination stack, separated by a space.

For example, your function may return the following list of actions "A C", "B C" and "A B" in order to move a box from A to C, then a box from B to C and then a box from A to B.

 
Victory Conditions
All boxes are piled on stack A, in order of size.
 
Lose Conditions
Your program outputs an invalid command.
Your program needs more than 200 commands.
Constraints
20 ≤ size ≤ 200
3 ≤ number of boxes ≤ 8
*/

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