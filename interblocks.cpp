#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <set>

using namespace std;

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