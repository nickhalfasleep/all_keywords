#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "ext.h"
using namespace std;

extern double super_ext;
// from https://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring

// trim from start (in place)
static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
            std::not1(std::ptr_fun<int, int>(std::isspace))));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
            std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

class WordSearch {
  public:
    WordSearch();

  private:
  int foo;
};

int main() {
  // 1.) Load up the reserved word file
  ifstream word_file ("keyword_list.txt");
  if (!word_file.is_open()) {
    return -1;
  }

  vector<string> word_list;
  string line;
  while ( getline(word_file,line) ) {
		trim(line);
    word_list.push_back(line);
	  cout << line << ", ";
  }
  unsigned short word_list_count = word_list.size();
  word_file.close();
  // 2.) Load up the file(s) to review
  // 3.) For each word, start a thread
  return 0;
}
