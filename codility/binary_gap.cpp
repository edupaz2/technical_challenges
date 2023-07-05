#include <iostream>
#include <math.h>

int numberOfBits(int number)
{
    return std::log2(number)+1;
}

int solution(int N) {
    // Implement your solution here
    int msb = numberOfBits(N);
    int longest = 0;
    bool oneFlag = false;
    int currentGap = 0;
    //std::cerr << "MSB " << msb << std::endl;
    for(int i=0; i <= msb; ++i) {
        //std::cerr << "Bit " << i << ", N: " << N << std::endl;
        if( N & 1 ) {
            //std::cerr << "HERE" << std::endl;
            if(currentGap > 0) {
                //std::cerr << "currentGap" << currentGap << std::endl;
                longest = std::max(longest, currentGap);
                currentGap = 0;
            }
            oneFlag = true;
        } else if(oneFlag) {
            //std::cerr << "HERE2" << std::endl;
            ++currentGap;
        }
        N = N >> 1;
    }
    return longest;
}

