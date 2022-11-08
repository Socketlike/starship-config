#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Language
{
  char* name;
  int count;
  char* dirmatch[100];
  char* filematch[100];
  char* extmatch[100];
};

// Insert your custom language matching here
struct Language lang[12] = {
  /* name     count   dir match            file dirmatch                                       extension match */
  {"c",       0,      {},                  {},                                                 {".c", ".h"}},
  {"cmake",   0,      {},                  {"CMakeCache.txt", "CMakeLists.txt"},               {}},
  {"dotnet",  0,      {},                  {".csproj", ".fsproj", ".xproj"},                   {"global.json", "project.json", "Directory.Build.props", "Directory.Build.targets", "Packages.props"}},
  {"elixir",  0,      {},                  {},                                                 {"mix.exs"}},
  {"elm",     0,      {"elm-stuff"},       {"elm.json", "elm-package.json", ".elm-version"},   {}},
  {"go",      0,      {"Godeps"},          {"go.mod", "go.work", "glide.yaml", "Gopkg.yaml"},  {}},
  {"haskell", 0,      {},                  {"stack.yaml", "cabal.project"},                    {".hs", ".cabal", ".hs_boot"}},
  {"java",    0,      {},                  {"pom.xml", "build.gradle.kts", "build.sbt", ".java-version", ".deps.edn", "project.clj", "build.boot"},
                                                                                               {".java", ".jar", ".class", ".cljs", ".cljc"}},
  {"julia",   0,      {},                  {"Manifest.toml", "Project.toml"},                  {".jl"}},
  {"nodejs",  0,      {"node_modules"},    {"package.json", ".node-version"},                  {".js", ".cjs", ".mjs", ".ts", ".mts", ".cts"}},
  {"nimble",  0,      {},                  {"nim.cfg"},                                        {".nim", ".nims", ".nimble"}},
  {"rust",    0,      {},                  {"Cargo.toml"},                                     {".rs"}}
};