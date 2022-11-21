#include <iostream>
#include <regex>
#include <string>
#include <filesystem>
#include <any>
#include "config.h"
using std::regex_match, std::regex, std::string;
namespace fs = std::filesystem;

int extcheck(string name, string ext) {
  if (regex_match(name, regex(".*\\." + ext + "$")))
    return 1;
  else return 0;
}

int streql(string string1, string string2) {
  if (string1 == string2)
    return 1;
  else return 0;
}

string matchlang(string name, int isDir) {
  int iterator = 0;
  struct Language *lang;
  for (struct Language l : languages) {
    if (isDir) {
      lang = &languages[iterator];
      for (string dirname : l.dirmatch) {
        if (streql(name, dirname)) {
          lang->count++;
          return l.name;
        }
      }
      iterator++;
    } else {
      lang = &languages[iterator];
      for (string filename : l.filematch) {
        if (streql(name, filename)) {
          lang->count++;
          return l.name;
        }
      }
      for (string extname : l.extmatch) {
        if (extcheck(name, extname)) {
          lang->count++;
          return l.name;
        }
      }
      iterator++;
    }
  }
  return "";
}

void scanCwd() {
  const fs::path cwd = fs::current_path();
  for (auto const& ent : fs::directory_iterator(cwd)) {
    if (!streql(ent.path().filename().string(), "..") && !streql(ent.path().filename().string(), "."))
      matchlang(ent.path().filename().string(), ent.is_directory());
  }
}

vector<int> getAvailables() {
  const int len = languages.size();
  vector<int> languageIds;

  for (int i = 0; i < len; i++) {
    if (languages[i].count > 0)
      languageIds.push_back(i);
  }

  return languageIds;
}

string what() {
  scanCwd();
  const vector<int> ids = getAvailables();
  string parsed = "";

  if (ids.size() == 0)
    exit(1);
  else
    for (int i = 0; i < ids.size(); i++) {
      if (i > 0)
        parsed = parsed + string(", ");
      parsed = parsed + languages[ids[i]].name;
    }

  return parsed;
}

void has() {
  scanCwd();
  const vector<int> ids = getAvailables();

  if (ids.size() == 0)
    exit(1);
  exit(0);
}

void no() {
  scanCwd();
  const vector<int> ids = getAvailables();

  if (ids.size() == 0)
    exit(0);
  exit(1);
}

int main(int argc, char* argv[]) {
  if (!argv[1] || streql(argv[1], "help")) {
    cout << "Usage: " << string(argv[0]) << " [OPTION]\n\n";
    cout << "  what            shows the most dominant language in current working directory\n";
    cout << "  has             exits with 1 if no files found, otherwise 0\n";
    cout << "  no              exits with 0 if no files found, otherwise 1\n";
  } else if (streql(argv[1], "what")) {
    cout << what() << '\n';
  } else if (streql(argv[1], "has")) {
    has();
  } else if (streql(argv[1], "no")) {
    no();
  } else {
    cout << "Usage: " + string(argv[0]) + " [OPTION]\n\n";
    cout << "  what            shows the most dominant language in current working directory\n";
    cout << "  has             exits with 1 if no files found, otherwise 0\n";
    cout << "  no              exits with 0 if no files found, otherwise 1\n";
  }
}