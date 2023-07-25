#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>

using namespace std;
/*
Goal
Find a pattern in an image.
  Rules
You are given 2 images: a base image and a pattern which may appear somewhere on this image.

Each image is represented by a vector of strings, where each element of the vector represents a row of pixels of the image, and each character represents one pixel. Understanding this encoding is not necessary to solve this problem, but for your information, a detailed explanation is provided below.

You must return the position x, y of this pattern in the image, or [-1, -1] if the pattern is not found. If the pattern appears multiple times, return the position of the highest one (the smallest y), and in case of equality, the leftmost one (the smallest x).

The position of the pattern is represented by the coordinates x, y of its top-left corner. x represents the column, y represents the row, and the coordinates [0, 0] represents the top-left corner.

  Implementation
Implement the function solve(imageWidth, imageHeight, image, patternWidth, patternHeight, pattern) where the parameters are:

imageWidth: the image width
imageHeight: the image height
image: the image as a vector of strings, where each character represents a pixel
patternWidth: the pattern width
patternHeight: the pattern height
pattern: the pattern as a vector of strings, where each character represents a pixel
and which should return:

if the pattern is present in the image: the position x, y, as a vector of 2 integers, representing the top-left corner of the first pattern, going from top to bottom and left to right.
if the pattern is not present in the image: [-1, -1]
 
Victory Conditions
The pattern is indeed located at coordinates x, y.
If the pattern appears multiple times, return the position of the highest one (the smallest y), and in case of equality, the leftmost one (the smallest x).
 
Defeat Conditions
The inner image that starts at coordinates x, y doesn't match the pattern.
You take longer than 1 second to anwser.
There's another matching pattern above or on the left.
Constraints
1 ≤ imageWidth ≤ 400
1 ≤ imageHeight ≤ 400
1 ≤ patternWidth ≤ 400
1 ≤ patternHeight ≤ 400
Response time ≤ 1s
 Encoding details
An image is initially a 2D-array of integers, where each integer represents a pixel (using RGB notation). All our images contain less than 62 different colors, so that we're able to encode each integer as a character among 0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ. We basically transformed the image into an array of strings, where the 1st string in the array is the 1st row of the image, etc.

For example, this 3x3 image:



is represented as a 2D integer array as:

[
  [0xff0000, 0x00ff00, 0x0000ff],
  [0xd3d3d3, 0x000000, 0xd3d3d3],
  [0xff0000, 0x00ff00, 0x0000ff]
]
which is then encoded as an array of strings as:

[
  "012",
  "343",
  "012"
]
*/


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