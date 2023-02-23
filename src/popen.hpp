#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <array>
using namespace std;

int propen(string command, string* result)
{
  if (command == string("") || !result)
     return 0;
  array<char, 128> buf;
  FILE* pipe = popen(command.c_str(), "r");
  if (!pipe) {
    cout << "Failed to execute " << command;
    return 0; 
  }
  while (fgets(buf.data(), 128, pipe) != NULL) {
    result = &(result->append(string(buf.data())));
  }
  pclose(pipe);
  return 1;
}
