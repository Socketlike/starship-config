#include <iostream>
#include <iterator>
#include <regex>
#include <string>
#include <filesystem>
#include "config.hpp"

int extcheck(std::string name, std::string ext) {
  if (std::regex_match(name, std::regex(".*\\." + ext + "$")))
    return 1;
  else return 0;
}

int streql(std::string string1, std::string string2) {
  if (string1 == string2)
    return 1;
  else return 0;
}

std::string matchlang(std::string name, int isDir) {
  int iterator = 0;
  struct Language *lang;
  for (struct Language l : languages) {
    if (isDir) {
      lang = &languages[iterator];
      for (std::string dirname : l.dirmatch) {
        if (streql(name, dirname)) {
          lang->count++;
          return l.name;
        }
      }
      iterator++;
    } else {
      lang = &languages[iterator];
      for (std::string filename : l.filematch) {
        if (streql(name, filename)) {
          lang->count++;
          return l.name;
        }
      }
      for (std::string extname : l.extmatch) {
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
  const std::filesystem::path cwd = std::filesystem::current_path();
  const std::filesystem::directory_iterator iterator = std::filesystem::directory_iterator(cwd);

  if (std::distance(iterator, {}) <= 1000)
    for (auto const& ent : iterator)
      if (!streql(ent.path().filename().string(), "..") && !streql(ent.path().filename().string(), "."))
        matchlang(ent.path().filename().string(), ent.is_directory());
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

std::string what() {
  scanCwd();
  const vector<int> ids = getAvailables();
  std::string parsed = "";

  if (ids.size() == 0)
    exit(1);
  else
    for (int i = 0; i < ids.size(); i++) {
      if (i > 0)
        parsed = parsed + std::string(", ");
      parsed = parsed.append(languages[ids[i]].name);
    }

  return parsed;
}

std::string symbols() {
  scanCwd();
  const vector<int> ids = getAvailables();
  std::string parsed = "";

  if (ids.size() == 0)
    exit(1);
  else
    for (int i = 0; i < ids.size(); i++) {
      parsed = parsed.append(languages[ids[i]].symbol);
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
    cout << "Usage: " << std::string(argv[0]) << " [OPTION]\n\n";
    cout << "  what            shows the most dominant language in current working directory\n";
    cout << "  has             exits with 1 if no files found, otherwise 0\n";
    cout << "  no              exits with 0 if no files found, otherwise 1\n";
    cout << "  symbols         shows symbols of respective languages in cwd\n";
  } else if (streql(argv[1], "what")) {
    cout << what() << '\n';
  } else if (streql(argv[1], "has")) {
    has();
  } else if (streql(argv[1], "no")) {
    no();
  } else if (streql(argv[1], "symbols")) {
    cout << symbols();
  } else {
    cout << "Usage: " + std::string(argv[0]) + " [OPTION]\n\n";
    cout << "  what            shows the most dominant language in current working directory\n";
    cout << "  has             exits with 1 if no files found, otherwise 0\n";
    cout << "  no              exits with 0 if no files found, otherwise 1\n";
    cout << "  symbols         shows symbols of respective languages in cwd\n";
  }
}