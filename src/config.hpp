#include <string>
#include <vector>
#include <regex>
using namespace std;

struct Language
{
  string name;
  string symbol;
  int count;
  vector<string> dirmatch;
  vector<string> filematch;
  vector<string> extmatch;
};

struct Distro
{
  regex name;
  string symbol;
};

/** 
 * Insert your custom language matching here
 * Do not set count to anything other than 0!
 * It is used internally.
 **/
vector<struct Language> languages = {
  /* name     sym   count   dir match            file match                                          extension match */
  {"c",       " ", 0,      {},                  {},                                                 {"c", "h"}},
  {"cpp",     " ", 0,      {},                  {},                                                 {"cpp", "hpp"}},
  {"cmake",   " ", 0,      {},                  {"CMakeCache.txt", "CMakeLists.txt"},               {}},
  {"crystal", " ", 0,      {},                  {"shard.yml"},                                      {"cr"}},
  {"dart",    " ", 0,      {".dart_tool"},      {"pubspec.yaml", "pubspec.yml", "pubspec.lock"},    {"dart"}},
  {"dotnet",  " ", 0,      {},                  {"global.json", "project.json", "Directory.Build.props", "Directory.Build.targets", "Packages.props"},
                                                                                                     {"csproj", "fsproj", "xproj"}},
  {"elixir",  " ", 0,      {},                  {"mix.exs"},                                        {}},
  {"elm",     " ", 0,      {"elm-stuff"},       {"elm.json", "elm-package.json", ".elm-version"},   {"elm"}},
  {"go",      " ", 0,      {"Godeps"},          {"go.mod", "go.work", "go.sum", "glide.yaml", "Gopkg.yml", "Gopkg.lock", ".go-version"},
                                                                                                     {"go"}},
  {"haskell", " ", 0,      {},                  {"stack.yaml", "cabal.project"},                    {"hs", "cabal", "hs_boot"}},
  {"java",    " ", 0,      {},                  {"pom.xml", "build.gradle.kts", "build.sbt", ".java-version", ".deps.edn", "project.clj", "build.boot"},
                                                                                                     {"java", "jar", "class", "cljs", "cljc"}},
  {"julia",   " ", 0,      {},                  {"Manifest.toml", "Project.toml"},                  {"jl"}},
  {"kotlin",  " ", 0,      {},                  {},                                                 {"kt", "kts"}},
  {"lua",     " ", 0,      {"lua"},             {".lua-version"},                                   {"lua"}},
  {"nodejs",  "󰌞 ", 0,      {"node_modules"},    {"package.json", ".node-version"},                  {"js", "cjs", "mjs", "ts", "mts", "cts"}},
  {"perl",    " ", 0,      {},                  {"Makefile.PL", "Build.PL", "cpanfile", "cpanfile.snapshot", "META.json", "META.yml", ".perl-version"},
                                                                                                     {"pl", "pm", "pod"}},
  {"python",  " ", 0,      {},                  {".python-version", "Pipfile", "__init__.py", "pyproject.toml", "requirements.txt", "setup.py", "tox.ini"},
                                                                                                     {"py"}},
  {"nimble",  " ", 0,      {},                  {"nim.cfg"},                                        {"nim", "nims", "nimble"}},
  {"rust",    " ", 0,      {},                  {"Cargo.toml"},                                     {"rs"}},
  {"ruby",    " ", 0,      {},                  {"Gemfile", ".ruby-version"},                       {"rb"}},
  {"zig",     " ", 0,      {},                  {},                                                 {"zig"}}
};

/**
 * Insert your custom distro matching here
 */
vector<struct Distro> distros = {
  /* match            sym */
  {regex("arch"),     " "},
  {regex("manjaro"),  " "},
  {regex("centos"),   " "},
  {regex("fedora"),   " "},
  {regex("rhel"),     " "},
  {regex("ubuntu"),   " "},
  {regex("mint"),     " "},
  {regex("gentoo"),   " "},
  {regex("debian"),   " "},
  {regex("opensuse"), " "},
  {regex("nixos"),    " "},
  {regex(".*"),       " "},
};