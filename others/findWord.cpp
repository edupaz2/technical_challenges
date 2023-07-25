
#include <vector>
#include <iostream>

bool findWord(char * wordToFind, char ** words) {

    while(*words != NULL)
    {
        if(strcmp(wordToFind, *words) == 0) {
            return true;
        }
        words++;
    }

    return false;
}

int main() {
    char* test[] = {(char*)("apple"), (char*)("orange"), (char*)("pear"), (char*)("banana"), NULL};
    std::cout << findWord((char*)("pear"), test) << std::endl;
}