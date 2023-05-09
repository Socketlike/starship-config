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

  std::smatch matches;

  std::ifstream osrelease ("/etc/os-release");
  std::ifstream issue ("/etc/issue");

  if (osrelease.is_open()) {
    while (std::getline(osrelease, line))
      if (std::regex_search(line, matches, regex("^ID=([a-zA-Z0-9_]+)")))
        distroName = matches[1];
  
  } else if (issue.is_open()) {
    while (std::getline(issue, line)) {
      std::string lowered = toLower(line);
      cout << lowered;
      if (std::regex_search(lowered, matches, regex("([a-z0-9_.])+.*")))
        distroName = matches[1];
    } 
  }

  if (osrelease.is_open()) osrelease.close();
  if (issue.is_open()) issue.close();

  return distroName;
};

std::string convertToSymbol(std::string distroName)
{
  for (struct Distro d : distros)
    if (std::regex_match(distroName, d.name))
      return d.symbol;

  return distros[distros.size() - 1].symbol;
}

int main()
{
  cout << convertToSymbol(getDistroName());
}
