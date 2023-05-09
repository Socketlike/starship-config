#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <iterator>
#include "config.hpp"

std::string toLower(string str)
{
  return std::to_string(std::tolower(*str.c_str()));
};

std::string getDistroName()
{
  std::string line;
  std::string distroName = "";

  std::array<std::ifstream, 2> files = {
    std::ifstream("/etc/os-release"),
    std::ifstream("/etc/issue"),
  };

  if (files.at(0).is_open()) {
    while (std::getline(files.at(0), line))
      if (std::regex_match(line, regex("^ID=.*")))
        distroName = line;
  } else if (files.at(1).is_open()) {
    std::smatch matches;

    while (std::getline(files.at(1), line)) {
      std::string lowered = toLower(line);
      cout << lowered;
      std::regex_search(lowered, matches, regex("([a-z0-9_.])+.*"));
      if (matches.length() > 0)
        distroName = matches[0];
    } 
  }

  for (std::ifstream *file = files.begin(); file != files.end(); ++file)
    (*file).close();

  return distroName;
};

std::string convertToSymbol(std::string distroName)
{
  for (struct Distro d : distros) {
    if (std::regex_match(distroName, d.name))
      return d.symbol;
  }

  return distros[distros.size() - 1].symbol;
}

int main()
{
  cout << convertToSymbol(getDistroName());
}
