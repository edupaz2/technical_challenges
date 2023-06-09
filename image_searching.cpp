#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>

using namespace std;


bool equals(const vector<string>& image, int i, int j, const vector<string>& pattern, int w, int h)
{
    //cerr << "Comparing: i:" << i << ", j:" << j << endl;
    return equal(image.begin() + i, image.begin() + i + h, pattern.begin(), [j, w](auto s1, auto s2){
        return s1.substr(j, w) == s2;
    });
}

vector<int> solve(int imageWidth, int imageHeight, vector<string> image, int patternWidth, int patternHeight, vector<string> pattern)
{
    // Write your code here
    // To debug: cerr << "Debug messages..." << endl;
    //cerr << "Image w:" << imageWidth << ", w:" << imageWidth << endl;
    //cerr << "Pattern w:" << patternWidth << ", w:" << patternHeight << endl;
    if(patternWidth > imageWidth ||
       patternHeight > imageHeight) {
        return {-1, -1};
    }
    
    for(int i = 0; i < imageHeight - patternHeight + 1; ++i) {
        for(int j = 0; j < imageWidth - patternWidth + 1; ++j) {
            if(equals(image, i, j, pattern, patternWidth, patternHeight)) {
                return {j, i};
            }
        }
    }

    return {-1, -1};
}

/* Ignore and do not change the code below */
int main()
{
    int image_width;
    int image_height;
    cin >> image_width >> image_height; cin.ignore();
    vector<string> image;
    for (int i = 0; i < image_height; i++) {
        string image_tmp;
        getline(cin, image_tmp);
        image.push_back(image_tmp);
    }
    int pattern_width;
    int pattern_height;
    cin >> pattern_width >> pattern_height; cin.ignore();
    vector<string> pattern;
    for (int i = 0; i < pattern_height; i++) {
        string pattern_tmp;
        getline(cin, pattern_tmp);
        pattern.push_back(pattern_tmp);
    }
    int std_out_fd = dup(1);
    dup2(2, 1);
    vector<int> coordinates = solve(image_width, image_height, image, pattern_width, pattern_height, pattern);
    dup2(std_out_fd, 1);
    for (int i = 0; i < 2; i++) {
        cout << coordinates[i] << endl;
    }
}
/* Ignore and do not change the code above */