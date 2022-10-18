#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <stdbool.h>

int endswith(const char* str, const char* suf)
{
    if (!str || !suf)
       return 0;
    size_t lenstr = strlen(str);
    size_t lensuf = strlen(suf);
    if (lensuf > lenstr)
       return 0;
    if (strncmp(str + lenstr - lensuf, suf, lensuf) == 0)
      return 1;
    else return 0;
}

int cmpstr(const char* str1, const char* str2)
{
  if (!str1 || !str2)
    return 0;
  if (strcmp(str1, str2) > 0 || strcmp(str1, str2) < 0)
    return 0;
  if (strcmp(str1, str2) == 0)
    return 1;
  else return 0;
}

int gethighest(int arr[])
{
   const int length = 12;
   int a, b;
   int tmp[12];

   for (int i = 0; i < length; i++)
    tmp[i] = arr[i];

   for (int i = 0; i < length; i++) {
      for (int j = i + 1; j < length; j++) {
         if (tmp[i] < tmp[j]) {
            a = tmp[i];
            tmp[i] = tmp[j];
            tmp[j] = a;
         }
      }
   }

   for (int i = 0; i < length; i++) {
    if (tmp[0] == arr[i])
      b = i;
   }

   return b;
}

int detectlang(const char* str)
{
    if (
        endswith(str, ".c") ||
        endswith(str, ".h")
       )
        return 1; // c
    else if (
        cmpstr(str, "CMakeCache.txt") ||
        cmpstr(str, "CMakeLists.txt")
       )
        return 2; // cmake
    else if (
        endswith(str, ".csproj") ||
        endswith(str, ".fsproj") ||
        endswith(str, ".xproj") ||
        cmpstr(str, "global.json") ||
        cmpstr(str, "project.json") ||
        cmpstr(str, "Directory.Build.props") ||
        cmpstr(str, "Directory.Build.targets") ||
        cmpstr(str, "Packages.props")
       )
        return 3; // dotnet
    else if (cmpstr(str, "mix.exs"))
        return 4; // elixir
    else if (
        cmpstr(str, "elm.json") ||
        cmpstr(str, "elm-package.json") ||
        cmpstr(str, ".elm-version") ||
        cmpstr(str, "elm-stuff")
       )
        return 5; // elm
    else if (
        cmpstr(str, "go.mod") ||
        cmpstr(str, "go.work") ||
        cmpstr(str, "glide.yaml") ||
        cmpstr(str, "Gopkg.yaml") ||
        cmpstr(str, "Godeps")
       )
        return 6; // go
    else if (
        endswith(str, ".hs") ||
        endswith(str, ".cabal") ||
        endswith(str, ".hs_boot") ||
        cmpstr(str, "stack.yaml") ||
        cmpstr(str, "cabal.project")
       )
        return 7; // haskell
    else if (
        endswith(str, ".java") ||
        endswith(str, ".class") ||
        endswith(str, ".jar") ||
        endswith(str, ".cljs") ||
        endswith(str, ".cljc") ||
        cmpstr(str, "pom.xml") ||
        cmpstr(str, "build.gradle.kts") ||
        cmpstr(str, "build.sbt") ||
        cmpstr(str, ".java-version") ||
        cmpstr(str, ".deps.edn") ||
        cmpstr(str, "project.clj") ||
        cmpstr(str, "build.boot")
       )
        return 8; // java
    else if (
        endswith(str, ".jl") ||
        cmpstr(str, "Manifest.toml") ||
        cmpstr(str, "Project.toml")
       )
        return 9; // julia
    else if (
        endswith(str, ".js") ||
        endswith(str, ".mjs") ||
        endswith(str, ".cjs") ||
        endswith(str, ".ts") ||
        endswith(str, ".mts") ||
        endswith(str, ".cts") ||
        cmpstr(str, "package.json") ||
        cmpstr(str, ".node-version") ||
        cmpstr(str, "node_modules")
       )
        return 10; // nodejs
    else if (
        endswith(str, ".nim") ||
        endswith(str, ".nims") ||
        endswith(str, ".nimble") ||
        cmpstr(str, "nim.cfg")
       )
        return 11; // nim
    else if (endswith(str, ".rs") || cmpstr(str, "Cargo.toml"))
        return 12; // rust
    else return 0; // none
}

void whatlang()
{
    DIR *dir = opendir("./");
    if (!dir)
       exit(EXIT_FAILURE);
    struct dirent *ent;
    
    /* index        language */
    /* 0            c        */
    /* 1            cmake    */
    /* 2            dotnet   */
    /* 3            elixir   */
    /* 4            elm      */
    /* 5            golang   */
    /* 6            haskell  */
    /* 7            java     */
    /* 8            julia    */
    /* 9            nodejs   */
    /* 10           nim      */
    /* 11           rust     */

    int languages[12];
    
    while ((ent = readdir(dir)) != NULL) {
        switch (detectlang(ent->d_name)) {
            case 0: break;
            case 1: languages[0]++; break;
            case 2: languages[1]++; break;
            case 3: languages[2]++; break;
            case 4: languages[3]++; break;
            case 5: languages[4]++; break;
            case 6: languages[5]++; break;
            case 7: languages[6]++; break;
            case 8: languages[7]++; break;
            case 9: languages[8]++; break;
            case 10: languages[9]++; break;
            case 11: languages[10]++; break;
            case 12: languages[11]++; break;
            default: break;
        }
    }

    closedir(dir);

    if (!languages[gethighest(languages)]) {
        exit(0);
    }

    switch (gethighest(languages)) {
      case 0: printf("c\n"); break;
      case 1: printf("cmake\n"); break;
      case 2: printf("dotnet\n"); break;
      case 3: printf("elixir\n"); break;
      case 4: printf("elm\n"); break;
      case 5: printf("golang\n"); break;
      case 6: printf("haskell\n"); break;
      case 7: printf("java\n"); break;
      case 8: printf("julia\n"); break;
      case 9: printf("nodejs\n"); break;
      case 10: printf("nim\n"); break;
      case 11: printf("rust\n"); break;
      default: break;
    }
}

void haslang()
{
    DIR *dir = opendir("./");
    if (!dir)
       exit(EXIT_FAILURE);
    struct dirent *ent;

    int lang = 0;
    
    while ((ent = readdir(dir)) != NULL) {
        if (lang) break;
        if (detectlang(ent->d_name))
            lang = 1;
    }

    closedir(dir);

    if (lang) exit(0);
    else exit(1);
}

void nolang()
{
    DIR *dir = opendir("./");
    if (!dir)
       exit(EXIT_FAILURE);
    struct dirent *ent;

    int lang = 0;
    
    while ((ent = readdir(dir)) != NULL) {
        if (lang) break;
        if (detectlang(ent->d_name))
            lang = 1;
    }

    closedir(dir);

    if (lang) exit(1);
    else exit(0);
}

int main(int argc, char *argv[])
{
    if (cmpstr(argv[1], "whatlang"))
        whatlang();
    else if (cmpstr(argv[1], "haslang"))
        haslang();
    else if (cmpstr(argv[1], "nolang"))
        nolang();
    else if (cmpstr(argv[1], "help")) {
        printf("Usage: %s [OPTION]\n", argv[0]);
        printf("Detect if working directory has a C, CMake, .NET, Elixir, Elm,\nGolang, Haskell, Java, Julia, NodeJS, Nim or Rust source file or show\nthe most dominant programming language in the current directory.\n\n");
        printf("  whatlang                   Shows the most dominant language in current directory\n");
        printf("  haslang                    Exits with 0 if there is a source file or 1 if there is\n");
        printf("                             no source files present.\n");
        printf("  nolang                     Does what \"haslang\" does but in reverse.\n");
    }
    else {
        printf("%s: missing option\nTry '%s help' for more information\n", argv[0], argv[0]);
        exit(0);
    }
}
