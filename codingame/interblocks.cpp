#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <set>

using namespace std;
/*
Objective
You make wooden toys in your woodworking shop for the enjoyment of your grandchildren. You have planned a serie of small puzzles, and you would like to automate the writing of their solutions.
Rules
Each puzzle is a grid, on which wooden blocks are placed. These blocks must be taken out of the game, one after the other, without colliding. You have to determine their movement sequence.
 
Each block is numbered with a value between 0 and 9. When you enter the number of a block and a direction, it will be moved until it is off of the grid.
 
If more than one block can be taken out at the same time, you can choose which one you would like to remove first.
 
If a block can be taken out to many directions, you can choose any one of them.
 Implementation
Implement the function solve(width, height, nbBlocks, grid). This function is executed at each round of the game and should return the number of the next block to move and its direction.
Input data of the function
width: width of the puzzle, in number of cells.
height: height of the puzzle, in number of cells.
nb_blocks: number of blocks initially present in the puzzle.
grid: a list of height elements, each of which is a string with a size equal to width.
The parameters width, height and nb_blocks do not change during the whole game.
 
The grid parameter represents the current situation of the puzzle. Each of its characters can take one of the following values :
. (a dot): an empty square.
X: a wall. They are placed on some borders of the puzzle. You cannot move these walls.
an integer between 0 and nb_blocks-1: a square occupied by a block. The same number can be present several times in the grid, representing a single block that extends over several squares. All cells with the same block number are connected (they are never separated into several isolated groups).
Output data of the function
A string, containing two data, separated by a space:
An integer, between 0 and nb_blocks-1, representing the number of the block you want to move.
The direction you would like to move the block in. There are 4 possible values:
UP
RIGHT
DOWN
LEFT
You can only move one block at a time. The block is moved until it either (a) exits the board entirely or (b) collides with another block.
 
Output example: 1 RIGHT
*/

bool canBlockBeExtractedUp(const vector<string>& grid, int w, int h, int block_number)
{
    vector<bool> found(w, false);
    cerr << "canBlockBeExtractedUp " << block_number << endl;
    for(int i = h-1; i >= 0; --i) {
        for(int j = 0; j < w; ++j) {
            if(!found[j]) {
                // We need to find the block first
                if(grid[i][j] != 'X' && grid[i][j] != '.' && stoi(grid[i].substr(j, 1)) == block_number) {
                    cerr << "i: " << i << ", j: " << j << ", block found" << endl;
                    found[j] = true;
                }
            } else {
                if(grid[i][j] == 'X') {
                    // Wall found
                    cerr << "i: " << i << ", j: " << j << ", wall found" << endl;
                    return false;
                } else if(grid[i][j] != '.') {
                    int number = stoi(grid[i].substr(j, 1));
                    if(block_number != number) {
                        // Other block in the way
                        cerr << "i: " << i << ", j: " << j << ", other block found" << endl;
                        return false;
                    } else {
                        cerr << "i: " << i << ", j: " << j << ", block found" << endl;
                    }
                }
            }
        }
    }
    cerr << "all good" << endl;
    return find(found.cbegin(), found.cend(), true) != found.cend();
}

bool canBlockBeExtractedDown(const vector<string>& grid, int w, int h, int block_number)
{
    cerr << "canBlockBeExtractedDown " << block_number << endl;
    vector<bool> found(w, false);
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            if(!found[j]) {
                // We need to find the block first
                if(grid[i][j] != 'X' && grid[i][j] != '.' && stoi(grid[i].substr(j, 1)) == block_number) {
                    cerr << "i: " << i << ", j: " << j << ", block found" << endl;
                    found[j] = true;
                }
            } else {
                if(grid[i][j] == 'X') {
                    // Wall found
                    cerr << "i: " << i << ", j: " << j << ", wall found" << endl;
                    return false;
                } else if(grid[i][j] != '.') {
                    int number = stoi(grid[i].substr(j, 1));
                    if(block_number != number) {
                        // Other block in the way
                        cerr << "i: " << i << ", j: " << j << ", other block found" << endl;
                        return false;
                    } else {
                        cerr << "i: " << i << ", j: " << j << ", block found" << endl;
                    }
                }
            }
        }
    }
    return find(found.cbegin(), found.cend(), true) != found.cend();
}

bool canBlockBeExtractedLeft(const vector<string>& grid, int w, int h, int block_number)
{
    vector<bool> found(h, false);
    cerr << "canBlockBeExtractedLeft " << block_number << endl;
    for(int j = w-1; j >= 0; --j) {
        for(int i = 0; i < h; ++i) {
            if(!found[i]) {
                // We need to find the block first
                if(grid[i][j] != 'X' && grid[i][j] != '.' && stoi(grid[i].substr(j, 1)) == block_number) {
                    cerr << "i: " << i << ", j: " << j << ", block found" << endl;
                    found[i] = true;
                }
            } else {
                if(grid[i][j] == 'X') {
                    // Wall found
                    cerr << "i: " << i << ", j: " << j << ", wall found" << endl;
                    return false;
                } else if(grid[i][j] != '.') {
                    int number = stoi(grid[i].substr(j, 1));
                    if(block_number != number) {
                        // Other block in the way
                        cerr << "i: " << i << ", j: " << j << ", other block found" << endl;
                        return false;
                    } else {
                        cerr << "i: " << i << ", j: " << j << ", block found" << endl;
                    }
                }
            }
        }
    }
    return find(found.cbegin(), found.cend(), true) != found.cend();
}

bool canBlockBeExtractedRight(const vector<string>& grid, int w, int h, int block_number)
{
    cerr << "canBlockBeExtractedRight " << block_number << endl;
    vector<bool> found(h, false);
    for(int j = 0; j < w; ++j) {
        for(int i = 0; i < h; ++i) {
            if(!found[i]) {
                // We need to find the block first
                if(grid[i][j] != 'X' && grid[i][j] != '.' && stoi(grid[i].substr(j, 1)) == block_number) {
                    cerr << "i: " << i << ", j: " << j << ", block found" << endl;
                    found[i] = true;
                }
            } else {
                if(grid[i][j] == 'X') {
                    // Wall found
                    cerr << "i: " << i << ", j: " << j << ", wall found" << endl;
                    return false;
                } else if(grid[i][j] != '.') {
                    int number = stoi(grid[i].substr(j, 1));
                    if(block_number != number) {
                        // Other block in the way
                        cerr << "i: " << i << ", j: " << j << ", other block found" << endl;
                        return false;
                    } else {
                        cerr << "i: " << i << ", j: " << j << ", block found" << endl;
                    }
                }
            }
        }
    }
    return find(found.cbegin(), found.cend(), true) != found.cend();
}

string solve(int width, int height, int nbBlocks, vector<string> grid)
{
    string result;
    // Write your code here
    // To debug: cerr << "Debug messages..." << endl;

    cerr << "Grid:" << endl;
    for(auto i: grid) {
        cerr << i << endl;
    }

    set<int> blocks;

    for(int i = 0; i < nbBlocks; ++i) {
        if(blocks.find(i) != blocks.end()) {
            continue;
        }
        cerr << "Block " << i << endl;
        string cmd;
        if(canBlockBeExtractedUp(grid, width, height, i)) {
            cerr << "Found UP" << endl;
            cmd = " UP";
        } else if(canBlockBeExtractedDown(grid, width, height, i)) {
            cerr << "Found DOWN" << endl;
            cmd = " DOWN";
        } else if(canBlockBeExtractedLeft(grid, width, height, i)) {
            cerr << "Found LEFT" << endl;
            cmd = " LEFT";
        } else if(canBlockBeExtractedRight(grid, width, height, i)) {
            cerr << "Found RIGHT" << endl;
            cmd = " RIGHT";
        }
        if(cmd.size()) {
            result.append(to_string(i));
            result.append(cmd);
            blocks.emplace(i);
            break;
        }
    }
    
    cerr << "CMD: " << result;
    return result;
}

/* Ignore and do not change the code below */
int main()
{
    int width;
    int height;
    int nb_blocks;
    cin >> width >> height >> nb_blocks; cin.ignore();

    // game loop
    while (1) {
        vector<string> grid;
        for (int i = 0; i < height; i++) {
            string grid_tmp;
            getline(cin, grid_tmp);
            grid.push_back(grid_tmp);
        }
        int std_out_fd = dup(1);
        dup2(2, 1);
        string moves = solve(width, height, nb_blocks, grid);
        dup2(std_out_fd, 1);
        cout << moves << endl;
    }
}
/* Ignore and do not change the code above */