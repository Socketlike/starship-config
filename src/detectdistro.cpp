#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <iterator>
#include "popen.h"
using namespace std;

int main()
{
  string ln;
  string distro;
  ifstream file ("/etc/os-release");
  if (file.is_open()) {
    while (getline(file, ln)) {
      if (regex_match(ln, regex("^ID=.*")))
        distro = ln;
    }
    file.close();
  } else {
    propen("cat /etc/issue | cut -d ' ' -f1 | tr -d '\n[:blank:]' | tr '[:upper:]' '[:lower:]'", &distro);
  }

  if (distro != string("")) {
    string res;
    regex_replace(back_inserter(res), distro.begin(), distro.end(), regex("^ID="), "");

    if (res == string("arch"))
      cout << " ";
    else if (res == string("manjaro"))
      cout << " ";
    else if (res == string("centos"))
      cout << " ";
    else if (res == string("fedora"))
      cout << " ";
    else if (res == string("rhel"))
      cout << " ";
    else if (res == string("ubuntu"))
      cout << " ";
    else if (res == string("mint"))
      cout << " ";
    else if (res == string("gentoo"))
      cout << " ";
    else if (res == string("debian"))
      cout << " ";
    else if (res == string("opensuse"))
      cout << " ";
    else if (res == string("nixos"))
      cout << " ";
    else
      cout << " ";

  } else {
    return 1;
  }
}
