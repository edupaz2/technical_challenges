
#include <iostream>
#include <vector>

bool findWord(char *wordToFind, char **words) {

  while (*words != nullptr) {
    if (strcmp(wordToFind, *words) == 0) {
      return true;
    }
    words++;
  }
  return false;
}

int main() {
  char *test[] = {"apple", "orange", "pear", "banana", nullptr};
  printf("%zu\n", sizeof test);
  printf("%zu\n", sizeof test / sizeof test[0]);
  std::cout << findWord("peara", test) << std::endl;
}

// bool findWord(char * wordToFind, char ** words) {

//     while(*words != NULL)
//     {
//         if(strcmp(wordToFind, *words) == 0) {
//             return true;
//         }
//         words++;
//     }

//     return false;
// }

// int main() {
//     char* test[] = {(char*)("apple"), (char*)("orange"), (char*)("pear"),
//     (char*)("banana"), NULL}; std::cout << findWord((char*)("pear"), test) <<
//     std::endl;
// }